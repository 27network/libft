/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:49:19 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/15 08:22:39 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <ft/data/list.h>
# include <stdbool.h>

typedef int		(*t_map_cmp)(void *a, void *b);

typedef struct s_map_item
{
	void		*key;
	void		*value;
}				t_map_item;

typedef struct s_map
{
	t_list		*items;
	t_map_cmp	cmp;
}				t_map;

typedef void	(*t_map_dealloc)(t_map_item *item);

t_map	*ft_map_new(t_map_cmp cmp);
void	*ft_map_get(t_map *map, void *key);
void	*ft_map_put(t_map *map, void *key, void *value, t_map_dealloc dealloc);
void	ft_map_remove(t_map *map, void *key, t_map_dealloc dealloc);
void	ft_map_clear(t_map *map, t_map_dealloc dealloc);
void	ft_map_destroy(t_map **map, t_map_dealloc dealloc);
bool	ft_map_contains(t_map *map, void *key);
size_t	ft_map_size(t_map *map);

#endif // MAP_H
