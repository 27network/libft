/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 08:35:37 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/11 09:19:08 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <ft/wchar.h>
#include <locale.h>

PRE({
	setlocale(LC_ALL, "");
})

char *do_tests() {
	const char* test_strings[] = {"Hello", "€uro", "\x80\x80", ""};

	for (int i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); i++) {
		const char* str = test_strings[i];
		// only use mbtowc

		wchar_t libc_wc;
		int libc_ret = mbtowc(&libc_wc, str, strlen(str));

		wchar_t ft_wc;
		int ft_ret = ft_mbtowc(&ft_wc, str, strlen(str));

		if (libc_wc != ft_wc) {
			return "mbtowc and ft_mbtowc returned different results";
		}
	}
	return NULL;
}

DEFINE_TEST(libwowccmp, "Compare conversions against the libc's implementation", {
	if (true)
		return do_tests();
})
