/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:32:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/01 19:29:20 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <ft_quick_sort.h>
#include <libft.h>
#include <ft_doubly_list.h>

t_result	*ft_make_result(t_d_list *memory)
{
	t_result		*new;
	t_d_list		*temp;
	unsigned int	index;
	unsigned int	len;

	temp = memory;
	len = 0;
	while (temp && ++len)
		temp = temp->next;
	if (!(len && ft_zeromalloc((void **)&new, sizeof(t_result)) && \
		ft_zeromalloc((void **)&new->result, sizeof(int) * len)))
		return (NULL);
	temp = memory;
	index = 0;
	while (index < len)
	{
		new->result[index++] = *temp->data;
		temp = temp->next;
	}
	new->index = index;
	new->last = index;
	return (new);
}

t_d_list	*ft_push_swap(t_d_list *memory)
{
	t_d_list_header	*a;
	t_d_list_header	*b;
	t_pivot			*pivot;
	t_result		*result;

	if (!memory)
		return (NULL);
	a = ft_d_list_header_init(memory);
	b = ft_d_list_header_init(NULL);
	pivot = ft_pivot_new(NULL, NULL);
	result = ft_make_result(memory);
	ft_quick_sort(result->result, 0, result->index - 1);
	if (result->index == 2)
		memory = ft_memory_two_a(a, result);
	else if (result->index == 3)
		memory = ft_memory_three_a(a, result);
	else
		memory = ft_pivot_split(a, b, pivot, result);
	free(result->result);
	free(result);
	free(pivot);
	free(a);
	free(b);
	return (memory);
}
