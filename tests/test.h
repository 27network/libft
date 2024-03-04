/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:13:54 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 23:40:54 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TEST_H__
#define __TEST_H__

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef char *testfunction_t(void);

typedef struct testdata {
	const char *file_name;
	const char *description;
	testfunction_t *test;
	struct testdata *next;
} testdata_t;

void ft_register_test(const char *file_name, const char *description, testfunction_t *test);

#define PRE(impl) \
	static void __attribute__((constructor)) __pre(void) { \
		impl \
	}

#define POST(impl) \
	static void __attribute__((destructor)) __post(void) { \
		impl \
	}

// define the name as the name of the file
#define DEFINE_TEST(unique_fct_name, description, impl) \
	char *unique_fct_name(void); \
	static void __attribute__((constructor)) __##unique_fct_name(void) { \
		ft_register_test(__FILE__, description, unique_fct_name); \
	} \
	char *unique_fct_name(void) { \
		impl \
		return NULL; \
	}

#define ASSERT(cond) \
	if (!(cond)) { \
		return "Assertion failed: "#cond; \
	}

#define ASSERT_EQ(a, b) \
	if ((a) != (b)) { \
		return "Assertion failed: "#a" == "#b; \
	}

#define ASSERT_NEQ(a, b) \
	if ((a) == (b)) { \
		return "Assertion failed: "#a" != "#b; \
	}

#define ASSERT_STR_EQ(a, b) \
	if (strcmp((a), (b)) != 0) { \
		return "Assertion failed: "#a" == "#b; \
	}

#define ASSERT_STR_NEQ(a, b) \
	if (strcmp((a), (b)) == 0) { \
		return "Assertion failed: "#a" != "#b; \
	}

// ANSI Colors from https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define GRAY "\e[0;90m"

#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

#define RESET "\e[0m"

#endif // __TEST_H__
