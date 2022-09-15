/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:31:02 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/01 22:33:13 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_quick_sort.h>
#include <ft_push_swap.h>
#include <ft_doubly_list.h>
#include <ft_printf_stack.h>
#include <ft_printf.h>

int	ft_matching_result(t_d_list *a_hold, t_result *result, t_pivot *pivot)
{
	t_d_list		*head;
	unsigned int	index;

	head = a_hold;
	index = result->p;
	while (head && *head->data == result->result[index])
	{
		pivot->a_hold = head;
		head = head->next;
		index++;
		result->p = index;
	}
	return (result->index - index);
}

t_d_list	*ft_pivot_split(t_d_list_header *a, t_d_list_header *b, \
	t_pivot *pivot, t_result *result)
{
	unsigned int	i;

	i = 0;
	if (!ft_matching_result(a->head, result, pivot))
		return (a->head);
	while (i++ < result->p)
		ft_ra(a);
	while (result->p < result->index)
	{
		if (result->last < result->p)
			result->last = result->p;
		if (a->head && *a->head->data != result->result[0])
			ft_pivot_split_a_left(a, b, &pivot, result);
		else if (b->head && b->head != pivot->b_hold)
			ft_pivot_split_b_left(a, b, &pivot, result);
		else if (b->head)
			ft_pivot_split_b_right(a, b, &pivot, result);
	}
	return (a->head);
}

int	ft_pivot_split_a_left(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot, t_result *result)
{
	int	middle;

	result->last = result->p + (result->last - result->p + 1) / 2;
	middle = result->result[result->last];
	ft_pivot_add(pivot, ft_pivot_new(NULL, NULL));
	while ((*a->head->data != result->result[0] || !(*pivot)->a_hold))
	{
		if (result->result[result->p] == *a->head->data && ft_ra(a) \
			&& ++result->p)
			(*pivot)->a_hold = a->tail;
		else if (ft_pb(a, b) && *b->head->data > middle && ft_rb(b))
		{
			if (!(*pivot)->b_hold)
				(*pivot)->b_hold = b->tail;
			if (!(*pivot)->head)
			{
				(*pivot)->head = b->tail;
				(*pivot)->tail = b->tail;
			}
			(*pivot)->tail = b->tail;
		}
	}
	if (!(*pivot)->head)
		ft_pivot_del(pivot);
	return (1);
}

int	ft_pivot_split_b_left(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot, t_result *result)
{
	int	middle;

	middle = result->result[result->last];
	ft_pivot_add(pivot, ft_pivot_new(NULL, NULL));
	while (b->head && b->head != (*pivot)->b_hold)
	{
		if (result->result[result->p] == *b->head->data && \
			ft_pa(a, b) && ft_ra(a) && ++result->p)
			(*pivot)->a_hold = a->tail;
		else if (*b->head->data <= middle)
			ft_pa(a, b);
		else if (ft_rb(b))
		{
			if (!(*pivot)->head)
				(*pivot)->head = b->tail;
			(*pivot)->tail = b->tail;
		}
	}
	if (!(*pivot)->head && (*pivot)->deep)
		ft_pivot_del(pivot);
	return (1);
}

int	ft_pivot_split_b_right(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot, t_result *result)
{
	int	middle;

	result->last = result->p + (result->index - result->p + 1) / 2;
	middle = result->result[result->last];
	while ((*pivot)->head != b->tail)
	{
		if (b->head != b->tail)
			ft_rrb(b);
		if (result->result[result->p] == *b->head->data && ft_pa(a, b) && \
			ft_ra(a) && ++result->p)
			(*pivot)->a_hold = a->tail;
		else if (*b->head->data <= middle)
			ft_pa(a, b);
	}
	if (b->head && ft_rrb(b))
		if (*b->head->data <= middle)
			ft_pa(a, b);
	if (!b->head)
		(*pivot)->b_hold = NULL;
	if ((*pivot)->deep)
		ft_pivot_del(pivot);
	return (1);
}
