/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:14:28 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/23 15:17:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_doubly_list.h>
#include <ft_quick_sort.h>
#include <libft.h>
#include <ft_stack.h>

void	ft_pivot_up_1(t_d_list_header *a, t_d_list_header *b)
{
	ft_pb(a, b);
}

void	ft_pivot_up_2(t_d_list_header *a, t_d_list_header *b)
{
	if (*a->head->data < *a->head->next->data)
		ft_sa(a);
	ft_pb(a, b);
	ft_pb(a, b);
}

void	ft_pivot_up_3(t_d_list_header *a, t_d_list_header *b)
{
	ft_pb(a, b);
	if (*a->head->data < *a->head->next->data)
		ft_sa(a);
	ft_pb(a, b);
	if (*b->head->data > *b->head->next->data)
		ft_sb(b);
	ft_pb(a, b);
	if (*b->head->data > *b->head->next->data)
		ft_sb(b);
}

void	ft_pivot_up_4(t_d_list_header *a, t_d_list_header *b)
{
	int	*result;
	int	i;

	result = (int [4]){*a->head->data, *a->head->next->data,
		*a->head->next->next->data,
		*a->head->next->next->next->data};
	ft_quick_sort(result, 0, 3);
	i = 3;
	if (result[i] == *a->head->data && ft_pb(a, b))
		ft_pivot_up_3(a, b);
	else if (result[i] == *a->head->next->data && ft_sa(a) && ft_pb(a, b))
		ft_pivot_up_3(a, b);
	else if (result[i] == *a->head->next->next->data)
	{
		ft_ra(a);
		ft_pb(a, b);
		ft_rb(b);
		ft_pb(a, b);
		while (i-- > 0)
		{
			if (result[i] == *a->head->data)
				ft_pb(a, b);
			else if (result[i] == *a->tail->data && ft_rra(a))
				ft_pb(a, b);
			else if (result[i] == *b->tail->data)
				ft_rrb(b);
		}
	}
	else
	{
		ft_ra(a);
		ft_pb(a, b);
		ft_rb(b);
		ft_sa(a);
		ft_pb(a, b);
		while (i-- > 0)
		{
			if (result[i] == *a->head->data)
				ft_pb(a, b);
			else if (result[i] == *a->tail->data && ft_rra(a))
				ft_pb(a, b);
			else if (result[i] == *b->tail->data)
				ft_rrb(b);
		}
	}
}

void	ft_pivot_up_5(t_d_list_header *a, t_d_list_header *b)
{
	int	*result;
	int	i;

	result = (int [5]){*a->head->data, *a->head->next->data, \
		*a->head->next->next->data, *a->head->next->next->next->data, \
		*a->head->next->next->next->next->data};
	ft_quick_sort(result, 0, 4);
	i = 4;
	if (result[i] == *a->head->data && ft_pb(a, b))
		ft_pivot_up_4(a, b);
	else if (result[i] == *a->head->next->data && ft_sa(a) && ft_pb(a, b))
		ft_pivot_up_4(a, b);
	else if (result[i] == *a->head->next->next->data)
	{
		ft_ra(a);
		ft_pb(a, b);
		ft_rb(b);
		ft_pb(a, b);
		if (*a->head->data < *a->head->next->data)
			ft_sa(a);
		while (i-- > 0)
		{
			if (result[i] == *a->head->data)
				ft_pb(a, b);
			else if (result[i] == *a->tail->data && ft_rra(a))
				ft_pb(a, b);
			else if (result[i] == *b->tail->data)
				ft_rrb(b);
		}
	}
	else if (result[i] == *a->head->next->next->next->data)
	{
		ft_ra(a);
		ft_pb(a, b);
		ft_rb(b);
		ft_sa(a);
		ft_pb(a, b);
		if (*a->head->data < *a->head->next->data)
			ft_sa(a);
		while (i-- > 0)
		{
			if (result[i] == *a->head->data)
				ft_pb(a, b);
			else if (result[i] == *a->tail->data && ft_rra(a))
				ft_pb(a, b);
			else if (result[i] == *b->tail->data)
				ft_rrb(b);
		}
	}
	else
	{
		if (*a->head->data > *a->head->next->data)
			ft_sa(a);
		ft_ra(a);
		ft_ra(a);
		ft_pb(a, b);
		ft_rb(b);
		ft_sa(a);
		ft_pb(a, b);
		while (i-- > 0)
		{
			if (result[i] == *a->head->data)
				ft_pb(a, b);
			else if (result[i] == *a->tail->data && ft_rra(a))
				ft_pb(a, b);
			else if (result[i] == *b->tail->data)
				ft_rrb(b);
		}
	}
}

int	ft_pivot_up(t_d_list_header *a, t_d_list_header *b, int len)
{
	if (len <= 1)
	{
		ft_pivot_up_1(a, b);
	}
	else if (len == 2)
	{
		ft_pivot_up_2(a, b);
	}
	else if (len == 3)
	{
		ft_pivot_up_3(a, b);
	}
	else if (len == 4)
	{
		ft_pivot_up_4(a, b);
	}
	else if (len == 5)
	{
		ft_pivot_up_5(a, b);
	}
	else
		return (0);
	return (1);
}
