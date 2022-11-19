/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:32:54 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/24 18:18:15 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_doubly_list.h>
#include <ft_quick_sort.h>
#include <ft_pivot.h>

int	*ft_result(t_d_list *memory)
{
	t_d_list	*temp;
	int			*result;
	int			len;

	len = 0;
	temp = memory;
	while (temp && ++len)
		temp = temp->next;
	if (!ft_zeromalloc((void **)&result, sizeof(int) * len))
		return (NULL);
	temp = memory;
	len = 0;
	while (temp)
	{
		result[len++] = *temp->data;
		temp = temp->next;
	}
	ft_quick_sort(result, 0, len - 1);
	return (result);
}

int	ft_matching_result(t_d_list *list_pir, int *result)
{
	t_d_list		*head;
	unsigned int	index;

	head = list_pir;
	index = 0;
	while (head && *head->data == result[index])
	{
		head = head->next;
		index++;
	}
	return (index);
}

t_pivot	*ft_pivot_free(t_pivot **pivot)
{
	if ((*pivot)->arrow)
		free((*pivot)->arrow);
	if ((*pivot)->len_arr)
		free((*pivot)->len_arr);
	if ((*pivot)->data)
	{
		while ((*pivot)->data_len--)
		{
			free((*pivot)->data[(*pivot)->data_len].arr);
		}
		free((*pivot)->data);
	}
	free(*pivot);
	return (*pivot);
}

void	ft_free_ab(t_d_list_header **a, t_d_list_header **b)
{
	free(*a);
	free(*b);
}

t_d_list	*ft_push_swap(t_d_list *memory)
{
	t_d_list_header	*a;
	t_d_list_header	*b;
	t_pivot			*pivot;
	int				*result;

	if (!memory)
		return (NULL);
	a = ft_d_list_header_init(memory);
	b = ft_d_list_header_init(NULL);
	result = ft_result(memory);
	pivot = ft_pivot_init(memory);
	if (ft_matching_result(memory, result) == pivot->index)
		;
	else if (pivot->index == 2)
		memory = ft_sort_two(a, result);
	else if (pivot->index == 3)
		memory = ft_sort_three(a, result);
	else if (pivot->index == 5)
		memory = ft_sort_five(a, b, result);
	else
		memory = ft_pivot_sort(a, b, pivot);
	free(result);
	ft_pivot_free(&pivot);
	ft_free_ab(&a, &b);
	return (memory);
}
