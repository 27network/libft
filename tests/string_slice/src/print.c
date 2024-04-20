/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:52:18 by kiroussa          #+#    #+#             */
/*   Updated: 2024/04/10 16:56:07 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <ft/string/slice.h>
#include <ft/print.h>

DEFINE_TEST(print_slice, "Can print a string slice", {
	t_string str = ft_str("Hello, World!");
	t_string slice = ft_str_new(str.base + 7, 5);

	int fds[2];
	pipe(fds);

	ft_dprintf(fds[1], "%S\n", &slice);

	char buf[64];
	read(fds[0], buf, sizeof(buf));
	buf[5] = '\0';
	ASSERT_STR_EQ(buf, "World");
	close(fds[0]);
	close(fds[1]);
});
