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
