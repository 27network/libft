/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:07:20 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 20:16:20 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef void	(*t_lst_dealloc)(void *);

t_list			*ft_lst_new(void *content);
void			ft_lst_free(t_list **lstptr, t_lst_dealloc dealloc);

t_list			*ft_lst_add(t_list **lstptr, t_list *new);
t_list			*ft_lst_tadd(t_list **lstptr, void *content);
size_t			ft_lst_size(t_list *list);
t_list			*ft_lst_insert(t_list **lstptr, t_list *new);
t_list			*ft_lst_tinsert(t_list **lstptr, void *content);
t_list			*ft_lst_last(t_list *list);
void			*ft_lst_tlast(t_list *list);

t_list			*ft_lst_remove(t_list **lst, t_list *node,
					t_lst_dealloc dealloc);

void			ft_lst_delete(t_list *list, t_lst_dealloc dealloc);

void			ft_lst_foreach(t_list *lst, void (*f)(void *));
t_list			*ft_lst_map(t_list *lst, void *(*f)(void *),
					t_lst_dealloc dealloc);

#endif
