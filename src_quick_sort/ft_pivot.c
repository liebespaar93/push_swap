/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:31:02 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/27 20:00:35 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_quick_sort.h>
#include <ft_doubly_list.h>


t_pivot	*ft_pivot_new(t_d_list *head, t_d_list *tail)
{
	t_pivot	*new;

	if (!ft_zeromalloc((void **)&new, sizeof(t_pivot)))
		return (NULL);
	new->head = head;
	new->tail = tail;
	return (new);
}

t_pivot	*ft_pivot_add(t_pivot **pivot_ptr, t_pivot *new)
{
	t_pivot	*pivot;

	if (!pivot_ptr || !new)
		return (NULL);
	pivot = *pivot_ptr;
	new->prev = pivot;
	new->a_hold = pivot->a_hold;
	new->b_hold = pivot->b_hold;
	new->deep = pivot->deep + 1;
	*pivot_ptr = new;
	return (new);
}

t_pivot	*ft_pivot_del(t_pivot **pivot_ptr)
{
	t_pivot	*pivot;

	if (!pivot_ptr)
		return (NULL);
	pivot = *pivot_ptr;
	if (!pivot)
		return (NULL);
	*pivot_ptr = pivot->prev;
	if (*pivot_ptr)
	{
		(*pivot_ptr)->a_hold = pivot->a_hold;
		(*pivot_ptr)->b_hold = pivot->b_hold;
	}
	free(pivot);
	return (*pivot_ptr);
}