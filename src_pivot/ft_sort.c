/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:33:58 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/01 22:04:35 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_doubly_list.h>
#include <ft_printf.h>
#include <ft_stack.h>

t_d_list	*ft_sort_two(t_d_list_header *a, int *result)
{
	if (result[0] != *a->head->data)
		ft_sa(a);
	else
		ft_printf("\n");
	return (a->head);
}

t_d_list	*ft_sort_three(t_d_list_header *a, int *result)
{
	if (result[2] != *a->tail->data)
	{
		if (result[2] == *a->head->next->data)
			ft_rra(a);
		else
			ft_ra(a);
	}
	if (result[0] != *a->head->data)
		ft_sa(a);
	else
		ft_printf("\n");
	return (a->head);
}

void	ft_sub_norm1(t_d_list_header *a, t_d_list_header *b, int *result, int i)
{
	ft_pb(a, b);
	if (*b->head->next->data > *b->head->data)
		ft_sb(b);
	i = 3;
	while (i != -1)
	{		
		if (result[i] == *a->tail->data)
			ft_rra(a);
		else if (b->head && result[i] == *b->head->data)
			ft_pa(a, b);
		else if (b->tail && result[i] == *b->tail->data && ft_rrb(b))
			ft_pa(a, b);
		i--;
	}
}

void	ft_sub_norm2(t_d_list_header *a, t_d_list_header *b, int *result, int i)
{
	ft_pb(a, b);
	if (*b->head->next->data > *b->head->data)
		ft_sb(b);
	if (*a->head->next->data < *a->head->data)
		ft_sa(a);
	i = 4;
	while (i != -1)
	{		
		if (result[i] == *a->tail->data)
			ft_rra(a);
		else if (b->head && result[i] == *b->head->data)
			ft_pa(a, b);
		else if (b->tail && result[i] == *b->tail->data && ft_rrb(b))
			ft_pa(a, b);
		i--;
	}
}

t_d_list	*ft_sort_five(t_d_list_header *a, t_d_list_header *b, int *result)
{
	int	i;

	i = 0;
	if (ft_pb(a, b) && ft_pb(a, b) && result[4] == *a->head->next->data)
	{
		if (result[3] == *a->head->data)
		{
			i = 2;
			while (i != -1)
			{
				if (result[i] == *a->tail->data)
					ft_rra(a);
				else if (b->head && result[i] == *b->head->data)
					ft_pa(a, b);
				else if (b->tail && result[i] == *b->tail->data && ft_rrb(b))
					ft_pa(a, b);
				i--;
			}
		}
		else
			ft_sub_norm1(a, b, result, i);
	}
	else
		ft_sub_norm2(a, b, result, i);
	return (a->head);
}
