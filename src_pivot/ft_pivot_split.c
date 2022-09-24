/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:14:12 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/24 15:20:32 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_pivot.h>
#include <ft_doubly_list.h>

t_pivot	*ft_pivot_split(t_d_list_header *a, t_d_list_header *b, t_pivot *pivot)
{
	int			index;

	index = 0;
	while (index < pivot->len)
	{
		if (pivot->arrow[index])
			ft_pivot_up(a, b, pivot->len_arr[index]);
		else
			ft_pivot_down(a, b, pivot->len_arr[index]);
		if (!ft_zeromalloc((void **)&pivot->data[index].arr, \
			sizeof(int) * pivot->data[index].len))
			return (NULL);
		ft_pdata_init(b, pivot, index);
		index++;
	}
	return (pivot);
}
