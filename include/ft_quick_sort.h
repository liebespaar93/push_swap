/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:43:09 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/27 18:13:52 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUICK_SORT_H
# define FT_QUICK_SORT_H

# include <ft_doubly_list.h>
# include <ft_push_swap.h>

typedef struct s_pivot	t_pivot;

typedef struct s_pivot
{
	t_d_list	*head;
	t_d_list	*tail;
	t_d_list	*a_hold;
	t_d_list	*b_hold;
	t_pivot		*prev;
	int			deep;
}	t_pivot;


t_pivot		*ft_pivot_new(t_d_list *head, t_d_list *tail);
t_pivot		*ft_pivot_add(t_pivot **pivot_ptr, t_pivot *new);
t_pivot		*ft_pivot_del(t_pivot **pivot_ptr);


t_d_list	*ft_quick_sort(t_d_list *memory);

t_d_list	*ft_pivot_split(t_d_list_header *a, t_d_list_header *b, t_pivot *pivot);

int			ft_pivot_split_a_left(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot);
int			ft_pivot_split_b_left(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot);
int			ft_pivot_split_a_right(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot);
int			ft_pivot_split_b_right(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot);

#endif