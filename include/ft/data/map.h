/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:49:19 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/22 18:40:18 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# undef MAP_H
# ifndef __FT_DATA_MAP_H__
#  define __FT_DATA_MAP_H__

#  include <ft/data/list.h>
#  include <stdbool.h>
#  include <stdint.h>

typedef uint64_t	t_map_hash_function(void *a);
typedef int32_t		t_map_cmp_function(void *a, void *b);

typedef struct s_map_node
{
	void	*key;
	void	*value;
}	t_map_node;

typedef void		t_map_dealloc(t_map_node *node);

typedef struct s_map
{
	t_list				**buckets;
	size_t				n_buckets;
	t_map_hash_function	*hash;
	t_map_cmp_function	*cmp;
}	t_map;

t_map	*ft_map_new(size_t buckets, t_map_hash_function *hash,
			t_map_cmp_function *cmp);
void	ft_map_free(t_map **map,
			t_map_dealloc *dealloc);

void	*ft_map_get(t_map *map, void *key);
void	*ft_map_put(t_map *map, void *key, void *value,
			t_map_dealloc *dealloc);
void	ft_map_remove(t_map *map, void *key,
			t_map_dealloc *dealloc);
void	ft_map_clear(t_map *map,
			t_map_dealloc *dealloc);

bool	ft_map_contains(t_map *map, void *key);
size_t	ft_map_size(t_map *map);

t_list	*ft_map_keys(t_map *map);

# endif // __FT_DATA_MAP_H__
#endif // MAP_H
