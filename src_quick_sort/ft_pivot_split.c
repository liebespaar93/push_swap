/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:31:02 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/01 07:33:51 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_quick_sort.h>
#include <ft_push_swap.h>
#include <ft_doubly_list.h>
#include <ft_printf_stack.h>
#include <ft_printf.h>


int ft_matching_result(t_d_list *a_hold, t_result *result, t_pivot *pivot)
{
	t_d_list *head;
	unsigned int index;


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

t_d_list	*ft_pivot_split(t_d_list_header *a, t_d_list_header *b, t_pivot *pivot, t_result *result)
{
	unsigned int i;

	i = 0;
	if (!ft_matching_result(a->head, result, pivot))
		return (a->head);
	while (i++ < result->p)
		ft_ra(a);
	i = 0;
	while (result->p < result->index && i++ < 8)
	{
		if (a->head && *a->head->data != result->result[0])
			ft_pivot_split_a_left(a, b, &pivot, result);
		else if (b->head && b->head != pivot->b_hold)
			ft_pivot_split_b_left(a, b, &pivot, result);
		else if (b->head)
			ft_pivot_split_b_right(a, b, &pivot, result);
	ft_printf_ab(a,b,0);
	}
	return (a->head);
}

int	ft_pivot_split_a_left(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot, t_result *result)
{
	int middle;
	
	result->last = result->p + (result->last - result->p + 1) / 2;
	middle = result->result[result->last];
	
	ft_pivot_add(pivot, ft_pivot_new(NULL, NULL));
	while (a->head && (*a->head->data != result->result[0] || !(*pivot)->a_hold))
	{
		if (result->result[result->p] == *a->head->data && ft_ra(a) && ++result->p)
			(*pivot)->a_hold = a->tail;
		else if (ft_pb(a,b) && *b->head->data > middle && ft_rb(b))
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
	int middle;
	
	result->last = result->p + (result->last - result->p + 1) / 2;
	middle = result->result[result->last];
	ft_pivot_add(pivot, ft_pivot_new(NULL, NULL));
	while (b->head && b->head != (*pivot)->b_hold)
	{
		if (result->result[result->p] == *b->head->data && ft_pa(a,b) && ft_ra(a) && ++result->p)
			(*pivot)->a_hold = a->tail;
		else if (*b->head->data <= middle)
			ft_pa(a,b);
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
	int middle;

	result->last = result->p + (result->index - result->p + 1) / 2;
	middle = result->result[result->last];
	while ((*pivot)->head != b->tail && ft_rrb(b))
	{
		if (result->result[result->p] == *b->head->data && ft_pa(a,b) && ft_ra(a) && ++result->p)
			(*pivot)->a_hold = a->tail;
		else if (*b->head->data <= middle)
			ft_pa(a,b);
	}
	if (b->head && ft_rrb(b))
		if (*b->head->data <= middle)
			ft_pa(a,b);
	if (!b->head)
		(*pivot)->b_hold = NULL;
	if ((*pivot)->deep)
		ft_pivot_del(pivot);
	return (1);
}





int	ft_pivot_split_a_right(t_d_list_header *a, t_d_list_header *b, \
	t_pivot **pivot, t_result *result)
{
	(void)result;
	if (a->tail->prev == (*pivot)->a_hold)
	{
		(*pivot)->a_hold = a->tail;
		return (0);
	}
	ft_pivot_add(pivot, ft_pivot_new(a->tail, a->tail));
	if (b->tail == NULL)
		(*pivot)->b_hold = a->tail;
	ft_rra(a);
	ft_pb(a,b);
	while ((*pivot)->a_hold != a->tail && ft_rra(a) && ft_pb(a,b))
		if (*((*pivot)->head->data) >= *b->head->data)
			ft_rb(b);
	(*pivot)->tail = b->head;
	if (a->head == NULL)
		(*pivot)->a_hold = NULL;
	return (1);
}










// int	ft_pivot_split_a_left(t_d_list_header *a, t_d_list_header *b, \
// 	t_pivot **pivot)
// {
// 	if (a->head->next == (*pivot)->a_hold && ft_pb(a,b))
// 	{
// 		(*pivot)->b_hold = b->head;
// 		return (0);
// 	}
// 	ft_pivot_add(pivot, ft_pivot_new(a->head, a->head));
// 	if (b->head == NULL)
// 		(*pivot)->b_hold = a->head;
// 	ft_pb(a,b);
// 	if (b->head != b->tail)
// 		ft_rb(b);
// 	while ((*pivot)->a_hold != a->head)
// 	{
// 		ft_pb(a,b);
// 		if (*((*pivot)->head->data) < *b->head->data && ft_rb(b))
// 			(*pivot)->tail = b->tail;
// 	}
// 	if (a->head == NULL)
// 		(*pivot)->a_hold = NULL;
// 	return (1);
// }

// int	ft_pivot_split_b_left(t_d_list_header *a, t_d_list_header *b, \
// 	t_pivot **pivot)
// {
// 	if (b->head->next == (*pivot)->b_hold)
// 	{
// 		(*pivot)->b_hold = b->head;
// 		return (0);
// 	}
// 	ft_pivot_add(pivot, ft_pivot_new(b->head, b->head));
// 	if (a->head == NULL)
// 		(*pivot)->a_hold = a->head;
// 	ft_pa(a,b);
// 	if (a->head != a->tail)
// 		ft_ra(a);
// 	while ((*pivot)->b_hold != b->head)
// 	{
// 		ft_pa(a,b);
// 		if (*((*pivot)->head->data) < *a->head->data && ft_ra(a))
// 			(*pivot)->tail = a->tail;
// 	}
// 	if (b->head == NULL)
// 		(*pivot)->b_hold = NULL;
// 	return (1);
// }

// int	ft_pivot_split_a_right(t_d_list_header *a, t_d_list_header *b, \
// 	t_pivot **pivot)
// {
// 	t_pivot	temp;

// 	temp = **pivot;
// 	(*pivot) =  ft_pivot_del(pivot);
// 	if (temp.head == temp.tail)
// 	{
// 		ft_rra(a);
// 		ft_pb(a,b);
// 		(*pivot)->b_hold = b->head;
// 		if (a->head == NULL)
// 			(*pivot)->a_hold = NULL;
// 		return (-1);
// 	}
// 	ft_rra(a);
// 	ft_pivot_add(pivot, ft_pivot_new(a->head, a->head));
// 	if ((*pivot)->b_hold == NULL)
// 		(*pivot)->b_hold = a->head;
// 	ft_pb(a,b);
// 	if (b->head != b->tail)
// 		ft_rb(b);
// 	while (temp.head != b->head)
// 	{
// 		ft_rra(a);
// 		ft_pb(a,b);
// 		if (*(*pivot)->head->data < *b->head->data && ft_rb(b))
// 			(*pivot)->tail = b->tail;
// 	}
// 	if (a->head == NULL)
// 		(*pivot)->a_hold = NULL;
// 	return (0);
// }

// int	ft_pivot_split_b_right(t_d_list_header *a, t_d_list_header *b, \
// 	t_pivot **pivot)
// {
// 	t_pivot	temp;

// 	temp = **pivot;
// 	(*pivot) = ft_pivot_del(pivot);
// 	ft_rrb(b);
// 	if (temp.head == temp.tail)
// 	{
// 		(*pivot)->b_hold = b->head;
// 		return (-1);
// 	}
// 	ft_pivot_add(pivot, ft_pivot_new(b->head, b->head));
// 	if ((*pivot)->a_hold == NULL)
// 		(*pivot)->a_hold = b->head;
// 	ft_pa(a,b);
// 	if (a->head != a->tail)
// 		ft_ra(a);
// 	while (temp.head != a->head)
// 	{
// 		ft_rrb(b);
// 		ft_pa(a,b);
// 		if (*(*pivot)->head->data < *a->head->data && ft_ra(a))
// 			(*pivot)->tail = a->tail;
// 	}
// 	if (b->head == NULL)
// 		(*pivot)->b_hold = NULL;
// 	return (0);
// }
