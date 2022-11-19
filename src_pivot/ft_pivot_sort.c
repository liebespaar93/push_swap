/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:26:20 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/24 15:23:30 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_pivot.h>
#include <ft_doubly_list.h>
#include <ft_stack.h>

t_d_list	*ft_pivot_sort(t_d_list_header *a, t_d_list_header *b, \
	t_pivot *pivot)
{
	pivot = ft_pivot_split(a, b, pivot);
	while (pivot->deep)
	{
		if (a->head)
			ft_pivot_split_a(a, b, pivot);
		else if (b->head)
			ft_pivot_split_b(a, b, pivot);
		pivot->len = pivot->len / 3;
		pivot->deep--;
	}
	if (b->head)
		while (pivot->index--)
			ft_pa(a, b);
	return (a->head);
}
