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
#include <ft_quick_sort.h>
#include <ft_push_swap.h>
#include <ft_doubly_list.h>
#include <ft_printf_stack.h>
#include <ft_printf.h>

t_d_list	*ft_memory_two_a(t_d_list_header *a, t_result *result)
{
	if (result->result[result->p] != *a->head->data)
		ft_sa(a);
	else
		ft_printf("\n");
	return (a->head);
}

t_d_list	*ft_memory_three_a(t_d_list_header *a, t_result *result)
{
	if (result->result[result->p + 2] != *a->tail->data)
	{
		if (result->result[result->p + 2] == *a->head->next->data)
			ft_rra(a);
		else
			ft_ra(a);
	}
	if (result->result[result->p] != *a->head->data)
		ft_sa(a);
	else
		ft_printf("\n");
	return (a->head);
}

t_d_list	*ft_memory_two_b(t_d_list_header *b, t_result *result)
{
	if (result->result[result->p] != *b->head->data)
		ft_sb(b);
	else
		ft_printf("\n");
	return (b->head);
}

t_d_list	*ft_memory_three_b(t_d_list_header *b, t_result *result)
{
	if (result->result[result->p + 2] != *b->tail->data)
	{
		if (result->result[result->p + 2] == *b->head->next->data)
			ft_rrb(b);
		else
			ft_rb(b);
	}
	if (result->result[result->p] != *b->head->data)
		ft_sb(b);
	else
		ft_printf("\n");
	return (b->head);
}
