/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:07:20 by kiroussa          #+#    #+#             */
/*   Updated: 2024/11/08 16:28:40 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# undef LIST_H
# ifndef __FT_DATA_LIST_H__
#  define __FT_DATA_LIST_H__

#  include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list __attribute__((aligned(1)));

typedef void	(*t_lst_dealloc)(void *);

t_list			*ft_lst_new(void *content);
void			ft_lst_free(t_list **lstptr, t_lst_dealloc dealloc);
t_list			*ft_lst_clone(t_list *list, t_lst_dealloc failsafe);

t_list			*ft_lst_add(t_list **lstptr, t_list *new);
t_list			*ft_lst_tadd(t_list **lstptr, void *content);
t_list			*ft_lst_get(t_list *list, size_t index);
void			*ft_lst_tget(t_list *list, size_t index);
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

#  ifdef __FT_LIBFT_COMPAT__

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lstptr, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lstptr, t_list *new);
void			ft_lstdelone(t_list *lst, t_lst_dealloc dealloc);
void			ft_lstclear(t_list **lstptr, t_lst_dealloc dealloc);
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					t_lst_dealloc dealloc);

#  endif // __FT_LIBFT_COMPAT__

# endif // __FT_DATA_LIST_H__
#endif // LIST_H
