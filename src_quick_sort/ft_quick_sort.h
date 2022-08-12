/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:43:09 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/13 05:26:15 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUICK_SORT_H
# define FT_QUICK_SORT_H

# include <ft_doubly_list.h>
# include <ft_push_swap.h>

t_d_list	*ft_quick_sort(t_d_list *memory, int max_len);

t_d_list	*ft_pivot_split(t_d_list_header *a, t_d_list_header *b, \
	t_d_list_header **pivot, int deep);
int			ft_pivot_split_a_left(t_d_list_header *a, t_d_list_header *b, \
	t_d_list_header **pivot, int *deep);
int			ft_pivot_split_b_left(t_d_list_header *a, t_d_list_header *b, \
	t_d_list_header **pivot, int *deep);
int			ft_pivot_split_a_right(t_d_list_header *a, t_d_list_header *b, \
	t_d_list_header **pivot, int *deep);
int			ft_pivot_split_b_right(t_d_list_header *a, t_d_list_header *b, \
	t_d_list_header **pivot, int *deep);

#endif