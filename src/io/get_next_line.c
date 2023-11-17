/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 03:36:48 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/17 03:37:57 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/internal/gnl.h>

static int	handle_read(t_gnl *gnl, char *read_buffer, ssize_t read_bytes)
{
	char	*tmp;

	tmp = gnl->inner;
	gnl->inner = ft_calloc(gnl->size + read_bytes + 1, sizeof(char));
	if (!gnl->inner)
		free(tmp);
	if (!gnl->inner)
		return (0);
	ft_memcpy(gnl->inner, tmp, gnl->size);
	ft_memcpy(gnl->inner + gnl->size, read_buffer, read_bytes);
	gnl->size += read_bytes;
	gnl->inner[gnl->size] = '\0';
	free(tmp);
	return (1);
}

static int	try_fill_buffer(int fd, t_gnl *gnl)
{
	ssize_t	read_bytes;
	char	*read_buffer;

	if (gnl->finished)
		return (1);
	read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buffer)
		return (0);
	read_bytes = -2;
	while (!gnl->inner || !ft_strchr(gnl->inner, '\n'))
	{
		read_bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		if (!handle_read(gnl, read_buffer, read_bytes))
			return (0);
	}
	free(read_buffer);
	if (read_bytes >= 0 && read_bytes != BUFFER_SIZE)
		gnl->finished = 1;
	return (read_bytes == -2 || read_bytes >= 0);
}

static char	*get_current_buffer(t_gnl *gnl)
{
	char	*line;

	if (!gnl->inner)
		return (NULL);
	line = ft_calloc(gnl->size + 1, sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, gnl->inner, gnl->size);
	line[gnl->size] = '\0';
	free(gnl->inner);
	gnl->inner = NULL;
	return (line);
}

static char	*get_line(t_gnl *gnl)
{
	char	*line;
	char	*tmp;
	size_t	line_len;

	if (!gnl->inner)
		return (NULL);
	if (!ft_strchr(gnl->inner, '\n'))
		return (get_current_buffer(gnl));
	line_len = ft_strchr(gnl->inner, '\n') - gnl->inner + 1;
	line = ft_calloc(line_len + 1, sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, gnl->inner, line_len);
	tmp = gnl->inner;
	gnl->inner = ft_calloc(gnl->size - line_len + 1, sizeof(char));
	if (!gnl->inner)
	{
		free(line);
		free(tmp);
		return (NULL);
	}
	ft_memcpy(gnl->inner, tmp + line_len, gnl->size - line_len);
	gnl->size -= line_len;
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_gnl	gnl[1024] = {{NULL, 0, 0}};
	char			*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!try_fill_buffer(fd, &gnl[fd]))
	{
		free(gnl[fd].inner);
		gnl[fd].inner = NULL;
		return (NULL);
	}
	line = get_line(&gnl[fd]);
	if ((!line || gnl[fd].size == 0) && gnl[fd].inner)
	{
		free(gnl[fd].inner);
		gnl[fd].inner = NULL;
	}
	return (line);
}
