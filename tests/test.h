/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:13:54 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/26 20:40:15 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TEST_H__
#define __TEST_H__

#include <libft.h>
#include <ft/colors.h>
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
	static void __attribute__((constructor)) __cxnstructor__##unique_fct_name(void) { \
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

#endif // __TEST_H__
