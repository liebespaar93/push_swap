/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:43:09 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/01 22:34:33 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUICK_SORT_H
# define FT_QUICK_SORT_H

# include <ft_doubly_list.h>
# include <ft_push_swap.h>

void		ft_quick_sort(int *array, int left, int right);
int			ft_matching_result(t_d_list *a_hold, \
	t_result *result, t_pivot *pivot);

t_pivot		*ft_pivot_new(t_d_list *head, t_d_list *tail);
t_pivot		*ft_pivot_add(t_pivot **pivot_ptr, t_pivot *new);
t_pivot		*ft_pivot_del(t_pivot **pivot_ptr);

t_d_list	*ft_memory_two_a(t_d_list_header *a, t_result *result);
t_d_list	*ft_memory_three_a(t_d_list_header *a, t_result *result);
t_d_list	*ft_memory_two_b(t_d_list_header *b, t_result *result);
t_d_list	*ft_memory_three_b(t_d_list_header *b, t_result *result);

t_d_list	*ft_pivot_split(t_d_list_header *a, t_d_list_header *b, \
	t_pivot *pivot, t_result *result);

int			ft_pivot_split_a_left(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot, t_result *result);
int			ft_pivot_split_b_left(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot, t_result *result);
int			ft_pivot_split_a_right(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot, t_result *result);
int			ft_pivot_split_b_right(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot, t_result *result);

#endif