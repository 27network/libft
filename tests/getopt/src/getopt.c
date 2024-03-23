/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:15:58 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/23 14:25:27 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
// #include <ft/opt.h>
//
// DEFINE_TEST(nocluehowtonameit, "Can parse short options", {
// 	t_opt_args program_args = ft_opt_args(
// 			4, {"./program", "-a", "-b", "-c", NULL}
// 	);
// 	t_opt_params params = ft_opt_params(
// 			program_args,
// 			"abc",
// 			NULL,
// 			NULL
// 	);
// })

#include <getopt.h>

DEFINE_TEST(actual_gnu_getopt, "Can parse short options", {
	int argc = 5;
	char *argv[] = {"./program", "-a", "-b", "Haiiii", "-c", "Hru?", NULL};
	int opt;
	int gots[3] = {0, 0, 0};
	while ((opt = getopt(argc, argv, "abc")) != -1)
	{
		switch (opt)
		{
			case 'a':
				gots[0] = 1;
				break;
			case 'b':
				gots[1] = 1;
				break;
			case 'c':
				gots[2] = 1;
				break;
			default:
				return "Invalid option found";
				break;
		}
	}
	ASSERT_EQ(gots[0], 1); // got a
	ASSERT_EQ(gots[1], 1); // got b
	ASSERT_EQ(gots[2], 1); // got c
	// optind should be 3
	ASSERT_EQ(optind, 3);
	// argv[optind] should be "Haiiii"
	ASSERT_STR_EQ(argv[optind], "Haiiii");
	// next option should be "Hru?"
	ASSERT_STR_EQ(argv[optind + 1], "Hru?");
})

