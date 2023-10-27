/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 00:08:37 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/27 02:10:27 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

TEST_ENTRY("ft_atof",
	TEST("test 1", 
		ASSERT(ft_atof("0") == 0.0);
		ASSERT(ft_atof("0.0") == 0.0);
		ASSERT(ft_atof("0.0000000000000000") == 0.0);
		ASSERT(ft_atof("000000.000000000000") == 0.0);
		ASSERT(ft_atof("42") != 0.0);
	)
	TEST("test 2", 
		ASSERT(ft_atof("1") == 1.0);
		ASSERT(ft_atof("1.0") == 1.0);
		ASSERT(ft_atof("1.0000000000000000") == 1.0);
	)
	TEST("1 decimal",
		ASSERT(ft_atof("1.1") == 1.1);
		ASSERT(ft_atof("1.9") == 1.9);
		ASSERT(ft_atof("0.1") == 0.1);
		ASSERT(ft_atof("0.9") == 0.9);
	)
)

