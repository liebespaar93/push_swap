/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubly_list_head_pop.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:30:25 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/25 09:12:20 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_doubly_list.h>
#include <libft.h>

t_d_list	*ft_d_list_header_pop_head(t_d_list_header *standard)
{
	t_d_list	*pop;

	if (!standard->head && ft_error_m("No head!"))
		exit(0);
	pop = standard->head;
	if (standard->head == standard->tail)
	{
		standard->head = NULL;
		standard->tail = NULL;
	}
	else
	{
		standard->head = standard->head->next;
		standard->head->prev = NULL;
	}
	pop->next = NULL;
	pop->prev = NULL;
	return (pop);
}

t_d_list	*ft_d_list_header_pop_tail(t_d_list_header *standard)
{
	t_d_list	*pop;

	if (!standard->tail && ft_error_m("No tail!"))
		exit(0);
	pop = standard->tail;
	if (standard->head == standard->tail)
	{
		standard->head = NULL;
		standard->tail = NULL;
	}
	else
	{
		standard->tail = standard->tail->prev;
		standard->tail->next = NULL;
	}
	pop->next = NULL;
	pop->prev = NULL;
	return (pop);
}
