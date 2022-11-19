/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:28:12 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/24 17:31:06 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_pivot.h>
#include <ft_doubly_list.h>

int	*ft_arrow_init(int *arrow, int deep)
{
	int	i;
	int	re_i;

	i = 0;
	if (deep % 2)
		arrow[i++] = 1;
	else
		arrow[i++] = 0;
	while (deep--)
	{
		re_i = 0;
		while (re_i < i)
		{
			arrow[i + re_i] = !arrow[i - 1 - re_i];
			arrow[i + i + re_i] = !arrow[i - 1 - re_i];
			re_i++;
		}
		i *= 3;
	}
	return (arrow);
}

int	*ft_arrow(int len)
{
	int		*arrow;
	int		i;
	int		deep;

	i = 1;
	deep = 0;
	while (i * 3 <= len && ++deep)
		i *= 3;
	if (!ft_zeromalloc((void **)&arrow, sizeof(int) * i))
		return (NULL);
	ft_arrow_init(arrow, deep);
	return (arrow);
}

int	*ft_len_arr(t_pivot *pivot)
{
	int	*len_arr;
	int	i;
	int	index;

	if (!ft_zeromalloc((void **)&len_arr, sizeof(int) * pivot->len))
		return (NULL);
	if (pivot->index / pivot->len >= 3.0)
		index = 3;
	if (pivot->index / pivot->len >= 2.0)
		index = 2;
	else if (pivot->index / pivot->len >= 1.0)
		index = 1;
	else
		index = 0;
	i = 0;
	while (i < pivot->len)
		len_arr[i++] = index;
	i = 0;
	while (i < pivot->index % pivot->len)
		len_arr[i++] += 1;
	return (len_arr);
}

t_pivot	*ft_pivot_init(t_d_list *memory)
{
	t_d_list	*temp;
	t_pivot		*pivot;

	temp = memory;
	if (!ft_zeromalloc((void **)&pivot, sizeof(t_pivot)))
		return (NULL);
	while (temp && ++pivot->index)
		temp = temp->next;
	pivot->len = 1;
	while (pivot->len * 3 <= pivot->index && ++pivot->deep)
		pivot->len *= 3;
	pivot->arrow = ft_arrow(pivot->index);
	pivot->len_arr = ft_len_arr(pivot);
	pivot->data_len = pivot->len;
	if (!ft_zeromalloc((void **)&pivot->data, sizeof(t_pdata) * pivot->len))
		return (NULL);
	return (pivot);
}
