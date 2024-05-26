/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:00:01 by kiroussa          #+#    #+#             */
/*   Updated: 2024/05/26 19:06:40 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static size_t	ft_strlen(char *s)
{
	const char	*tmp = s;

	while (*s)
		s++;
	return (s - tmp);
}

static bool	exists(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	(void) close(fd);
	return (true);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!exists(argv[i]))
		{
			(void) write(1, argv[i], ft_strlen(argv[i]));
			if (i != argc - 1)
				(void) write(1, " ", 1);
		}
		i++;
	}
	(void) write(1, "\n", 1);
	return (0);
}
