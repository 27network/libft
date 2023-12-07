/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:36:07 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/07 12:46:49 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <ft/io.h>
# include <ft/mem.h>
# include <ft/string.h>

# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl
{
	char	*inner;
	size_t	size;
}	t_gnl;

#endif // GNL_H
