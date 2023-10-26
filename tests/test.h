/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 00:09:46 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/26 02:46:25 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# include <ft/colors.h>
# include <ft/io.h>
# include <ft/list.h>
# include <ft/log.h>
# include <ft/macros.h>
# include <ft/mem.h>
# include <ft/string/parse.h>
# include <ft/string.h>
# include <ft/types.h>

# define ASSERT(expr) \
	if (!(expr)) \
	{ \
		ft_log(ERROR, "ft_tests", "Assertion " RED "failed: " RESET BOLD #expr RESET); \
		exit(1); \
	}

# define TEST_ENTRY(name, tests) \
	int	main(void) \
	{ \
		int test_count = 0; \
		int test_passed = 0; \
		ft_log(TRACE, "ft_tests", RESET "Starting tests for " BOLD name RESET); \
		char *test_name = name; \
		tests; \
		char *nb_tests = ft_itoa(test_count); \
		char *nb_passed = ft_itoa(test_passed); \
		char *msg_str = RESET BOLD; \
		msg_str = ft_strjoin(msg_str, nb_passed); \
		msg_str = ft_strjoin(msg_str, RESET "/" BOLD); \
		msg_str = ft_strjoin(msg_str, nb_tests); \
		msg_str = ft_strjoin(msg_str, RESET " tests passed"); \
		ft_log(TRACE, "ft_tests", msg_str); \
		return (0); \
	}

# define TEST(name, test) \
	{ \
		test_count++; \
		ft_log(INFO, test_name, RESET "Running test " GREEN name RESET); \
		int pid = fork(); \
		if (pid == 0) \
		{ \
			test; \
			exit(0); \
		} else {\
			int status; \
			waitpid(pid, &status, 0); \
			if (status == 0) \
				test_passed++; \
		} \
	}

#endif
