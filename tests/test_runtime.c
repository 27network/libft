/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runtime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:43:18 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 19:15:23 by kiroussa         ###   ########.fr       */
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
#define OK(...) printf(GRN OKCHAR RESET" "__VA_ARGS__)

#define ERRORCHAR "✗ Failure"
#define ERROR(...) fprintf(stderr, RED ERRORCHAR RESET" "__VA_ARGS__)

static testdata_t *g_tests = NULL;

void ft_register_test(const char *file_name, const char *description, testfunction_t *test) {
	testdata_t *new = calloc(sizeof(testdata_t), 1);
	if (!new) {
		fprintf(stderr, "[INTERNAL ERROR] Failed to allocate memory for test data: %s\n", strerror(errno));
		exit(1);
	}
	new->file_name = file_name;
	new->description = description;
	new->test = test;
	new->next = g_tests;
	g_tests = new;
}

int	main(void) {
	testdata_t *test = g_tests;
	if (!test) {
		printf("No tests found, aborting...\n");
		return 0;
	}

	int longest_name = 0;
	while (test) {
		size_t len = strlen(test->file_name + 4);
		if (len > longest_name)
			longest_name = len;
		test = test->next;
	}
	test = g_tests;

	clock_t root_start = clock();
	while (test) {
		clock_t start = clock();
		char *result = test->test();
		clock_t end = clock();
		if (!result)
			OK(WHT "%*s" RESET " %s " GRAY "(took %f seconds)"RESET"\n", longest_name, test->file_name + 4, test->description, (double)(end - start) / CLOCKS_PER_SEC);
		else {
			ERROR(WHT "%*s" RESET" %s\n" RESET, longest_name, test->file_name + 4, test->description);
			fprintf(stderr, "%*s> %s\n", (int) (longest_name + strlen(ERRORCHAR)), "", result);
		}
		test = test->next;
	}
	clock_t root_end = clock();
	//printf("\nFinished in %f seconds\n", (double)(root_end - root_start) / CLOCKS_PER_SEC);
	testdata_t *next;
	while (g_tests) {
		next = g_tests->next;
		free(g_tests);
		g_tests = next;
	}
	return 0;
}
