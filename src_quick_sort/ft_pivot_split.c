/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:31:02 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/29 14:56:01 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_quick_sort.h>
#include <ft_push_swap.h>
#include <ft_doubly_list.h>
#include <ft_printf_stack.h>
#include <ft_printf.h>
t_d_list	*ft_pivot_split(t_d_list_header *a, t_d_list_header *b, t_pivot *pivot)
{
	while (!(pivot->deep == 0 && pivot->b_hold))
	{
		if (a->head && pivot->a_hold != a->head)
			ft_pivot_split_a_left(a, b, &pivot);
		else if (b->head && pivot->b_hold != b->head)
			ft_pivot_split_b_left(a, b, &pivot);
		else if (a->head && pivot->tail == a->tail)
			ft_pivot_split_a_right(a, b, &pivot);
		else if (b->head && pivot->tail == b->tail)
			ft_pivot_split_b_right(a, b, &pivot);
	ft_printf_ab(a,b,0);
		ft_printf("deep : %d\n", (*pivot).deep);
	}
	while (b->head)
		ft_pa(a, b);
	return (a->head);
}

int	ft_pivot_split_a_left(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot)
{
	if (a->head->next == (*pivot)->a_hold && ft_pb(a,b))
	{
		(*pivot)->b_hold = b->head;
		return (0);
	}
	ft_pivot_add(pivot, ft_pivot_new(a->head, a->head));
	if (b->head == NULL)
		(*pivot)->b_hold = a->head;
	ft_pb(a,b);
	if (b->head != b->tail)
		ft_rb(b);
	while ((*pivot)->a_hold != a->head)
	{
		ft_pb(a,b);
		if (*((*pivot)->head->data) < *b->head->data && ft_rb(b))
			(*pivot)->tail = b->tail;
	}
	if (a->head == NULL)
		(*pivot)->a_hold = NULL;
	return (1);
}

int	ft_pivot_split_b_left(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot)
{
	if (b->head->next == (*pivot)->b_hold)
	{
		(*pivot)->b_hold = b->head;
		return (0);
	}
	ft_pivot_add(pivot, ft_pivot_new(b->head, b->head));
	if (a->head == NULL)
		(*pivot)->a_hold = a->head;
	ft_pa(a,b);
	if (a->head != a->tail)
		ft_ra(a);
	while ((*pivot)->b_hold != b->head)
	{
		ft_pa(a,b);
		if (*((*pivot)->head->data) < *a->head->data && ft_ra(a))
			(*pivot)->tail = a->tail;
	}
	if (b->head == NULL)
		(*pivot)->b_hold = NULL;
	return (1);
}

int	ft_pivot_split_a_right(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot)
{
	t_pivot	temp;

	temp = **pivot;
	(*pivot) =  ft_pivot_del(pivot);
	if (temp.head == temp.tail)
	{
		ft_rra(a);
		ft_pb(a,b);
		(*pivot)->b_hold = b->head;
		if (a->head == NULL)
			(*pivot)->a_hold = NULL;
		return (-1);
	}
	ft_rra(a);
	ft_pivot_add(pivot, ft_pivot_new(a->head, a->head));
	if ((*pivot)->b_hold == NULL)
		(*pivot)->b_hold = a->head;
	ft_pb(a,b);
	if (b->head != b->tail)
		ft_rb(b);
	while (temp.head != b->head)
	{
		ft_rra(a);
		ft_pb(a,b);
		if (*(*pivot)->head->data < *b->head->data && ft_rb(b))
			(*pivot)->tail = b->tail;
	}
	if (a->head == NULL)
		(*pivot)->a_hold = NULL;
	return (0);
}

int	ft_pivot_split_b_right(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot)
{
	t_pivot	temp;

	temp = **pivot;
	(*pivot) = ft_pivot_del(pivot);
	ft_rrb(b);
	if (temp.head == temp.tail)
	{
		(*pivot)->b_hold = b->head;
		return (-1);
	}
	ft_pivot_add(pivot, ft_pivot_new(b->head, b->head));
	if ((*pivot)->a_hold == NULL)
		(*pivot)->a_hold = b->head;
	ft_pa(a,b);
	if (a->head != a->tail)
		ft_ra(a);
	while (temp.head != a->head)
	{
		ft_rrb(b);
		ft_pa(a,b);
		if (*(*pivot)->head->data < *a->head->data && ft_ra(a))
			(*pivot)->tail = a->tail;
	}
	if (b->head == NULL)
		(*pivot)->b_hold = NULL;
	return (0);
}
