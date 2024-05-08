/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runtime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:43:18 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/08 14:40:20 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#ifndef TEST_NAME
# ifndef BUILD
#  define TEST_NAME "unknown"
# else
#  error "TEST_NAME must be defined"
# endif // BUILD
#endif // TEST_NAME

#define OKCHAR "✓ Success"
#define OK(...) printf(GREEN OKCHAR RESET" "__VA_ARGS__)

#define ERRORCHAR "✗ Failure"
#define ERROR(...) fprintf(stderr, RED ERRORCHAR RESET" "__VA_ARGS__)

static testdata_t *g_tests = NULL;

void ft_register_test(const char *file_name, const char *description, testfunction_t *test)
{
	testdata_t *new;

	new = calloc(sizeof(testdata_t), 1);
	if (!new)
	{
		fprintf(stderr, "[INTERNAL ERROR] Failed to allocate memory for test data: %s\n", strerror(errno));
		exit(1);
	}
	new->file_name = file_name;
	new->description = description;
	new->test = test;
	new->next = g_tests;
	g_tests = new;
}

int	main(void)
{
	testdata_t	*test;
	size_t		longest_name;
	size_t		len;
	clock_t		root_start;
	clock_t		root_end;
	clock_t		start;
	clock_t		end;
	char		*result;

	if (!g_tests)
	{
		printf("No tests found, aborting...\n");
		return 0;
	}

	test = g_tests;
	longest_name = 0;
	while (test)
	{
		len = strlen(test->file_name + 4);
		if (len > longest_name)
			longest_name = len;
		test = test->next;
	}
	test = g_tests;

	root_start = clock();
	while (test)
	{
		start = clock();
		result = test->test();
		end = clock();
		if (!result)
			OK(WHITE "%*s" RESET " %s " DARK_GRAY "(took %f seconds)"RESET"\n", longest_name, test->file_name + 4, test->description, (double)(end - start) / CLOCKS_PER_SEC);
		else 
		{
			ERROR(WHITE "%*s" RESET" %s\n" RESET, longest_name, test->file_name + 4, test->description);
			fprintf(stderr, "%*s> %s\n", (int) (longest_name + strlen(ERRORCHAR)), "", result);
		}
		test = test->next;
	}
	root_end = clock();
	while (g_tests)
	{
		test = g_tests->next;
		free(g_tests);
		g_tests = test;
	}
	return 0;
}
