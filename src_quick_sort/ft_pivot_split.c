/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:31:02 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 21:48:02 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_quick_sort.h>
#include <ft_push_swap.h>
#include <ft_doubly_list.h>
#include <ft_printf_stack.h>

t_d_list	*ft_pivot_split(t_d_list_header *a, t_d_list_header *b, \
	t_d_list_header **pivot, int deep)
{
	while (deep > 0)
	{
		if (a->head && pivot[1]->head != a->head)
			ft_pivot_split_a_left(a, b, pivot, &deep);
		else if (b->head && pivot[0]->head != b->head)
			ft_pivot_split_b_left(a, b, pivot, &deep);
		else if (a->head && pivot[deep]->tail == a->tail)
			ft_pivot_split_a_right(a, b, pivot, &deep);
		else if (b->head && pivot[deep]->tail == b->tail)
			ft_pivot_split_b_right(a, b, pivot, &deep);
		if (deep == 1)
			break ;
		ft_printf_ab(a, b, pivot);
	}
	while (b->head)
		ft_pa(a, b);
	ft_printf_ab(a, b, pivot);
	return (a->head);
}

int	ft_pivot_split_a_left(t_d_list_header *a, t_d_list_header *b, \
	t_d_list_header **pivot, int *deep)
{
	int	*check;

	check = (int [2]){0, 0};
	pivot[++(*deep)]->head = a->head;
	if (a->head && ft_pb(a, b))
		ft_rb(b);
	while (a->head && pivot[1]->head != a->head)
	{
		check[0] += ft_pb(a, b);
		if (*(pivot[*deep]->head->data) < *b->head->data)
			check[1] += ft_rb(b);
	}
	if (!a->head)
		ft_bzero(pivot[1], sizeof(t_d_list_header));
	pivot[*deep]->tail = b->tail;
	return (check[0] - check[1]);
}

int	ft_pivot_split_b_left(t_d_list_header *a, t_d_list_header *b, \
	t_d_list_header **pivot, int *deep)
{
	int	*check;

	check = (int [2]){0, 0};
	pivot[++(*deep)]->head = b->head;
	if (!a->head)
		ft_memcpy(pivot[1], pivot[*deep], sizeof(t_d_list_header));
	if (b->head && ft_pa(a, b))
		ft_ra(a);
	while (b->head && pivot[0]->head != b->head)
	{
		check[0] += ft_pa(a, b);
		if (*(pivot[*deep]->head->data) < *a->head->data)
			check[1] += ft_ra(a);
	}
	pivot[*deep]->tail = a->tail;
	return (check[0] - check[1]);
}

int	ft_pivot_split_a_right(t_d_list_header *a, t_d_list_header *b, \
	t_d_list_header **pivot, int *deep)
{
	int				*check;
	t_d_list_header	pivot_data;

	check = (int [2]){0, 0};
	if (a->tail && pivot[*deep]->head == a->tail && ft_rra(a) && ft_pb(a, b))
	{
		pivot[0]->head = b->head;
		ft_bzero(pivot[(*deep)--], sizeof(t_d_list_header));
		if (!a->head)
			ft_bzero(pivot[1], sizeof(t_d_list_header));
		return (-1);
	}
	pivot_data = *pivot[*deep];
	pivot[*deep]->head = a->tail;
	if (a->tail && ft_rra(a) && ft_pb(a, b) && ft_rb(b))
		while (a->tail && pivot_data.head != a->tail && ++check[0])
			if (ft_rra(a) && ft_pb(a, b))
				if (*(pivot[*deep]->head->data) < *b->head->data)
					check[1] += ft_rb(b);
	if (a->tail && pivot_data.head == a->tail && ft_rra(a))
		ft_pb(a, b);
	pivot[*deep]->tail = b->tail;
	if (!a->head)
		ft_bzero(pivot[1], sizeof(t_d_list_header));
	return (check[0] - check[1]);
}

int	ft_pivot_split_b_right(t_d_list_header *a, t_d_list_header *b, \
	t_d_list_header **pivot, int *deep)
{
	int				*check;
	t_d_list_header	pivot_data;

	check = (int [2]){0, 0};
	if (b->tail && pivot[*deep]->head == b->tail && ft_rrb(b))
	{
		pivot[0]->head = b->head;
		ft_bzero(pivot[(*deep)--], sizeof(t_d_list_header));
		return (-1);
	}
	pivot_data = *pivot[*deep];
	pivot[*deep]->head = b->tail;
	if (!a->head)
		ft_memcpy(pivot[1], pivot[*deep], sizeof(t_d_list_header));
	if (b->tail && ft_rrb(b) && ft_pa(a, b))
		ft_ra(a);
	while (b->tail && pivot_data.head != b->tail && ++check[0] && ft_rrb(b))
		if (ft_pa(a, b) && *(pivot[*deep]->head->data) < *a->head->data)
			check[1] += ft_ra(a);
	if (b->tail && pivot_data.head == b->tail && ft_rrb(b))
		pivot[0]->head = b->head;
	pivot[*deep]->tail = a->tail;
	return (check[0] - check[1]);
}
