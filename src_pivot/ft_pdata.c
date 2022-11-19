/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:54:27 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/24 15:31:22 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_pivot.h>
#include <ft_doubly_list.h>

void	ft_pdata_init(t_d_list_header *header, t_pivot *pivot, int index)
{
	t_d_list	*temp;
	int			i;

	temp = header->head;
	pivot->data[index].len = pivot->len_arr[index];
	i = 0;
	if (index < pivot->len / 3)
	{
		while (i++ < pivot->data[index].len - 1)
			temp = temp->next;
		i = 0;
		while (i < pivot->data[index].len)
		{
			pivot->data[index].arr[i++] = *temp->data;
			temp = temp->prev;
		}
	}
	else
	{
		while (i < pivot->data[index].len)
		{
			pivot->data[index].arr[i++] = *temp->data;
			temp = temp->next;
		}
	}
}

t_pdata	*ft_find_pdata(t_pivot *pivot, int num)
{
	int	i;

	i = 0;
	while (i < pivot->len)
	{
		if (pivot->data[i].arr[0] == num)
			return (&pivot->data[i]);
		i++;
	}
	return (NULL);
}

void	ft_pdata_arr_up(t_d_list_header *header, int len, t_pdata *data)
{
	t_d_list	*temp;
	int			i;

	temp = header->head;
	free(data->arr);
	if (!ft_zeromalloc((void **)&data->arr, sizeof(int) * len))
		return ;
	i = 0;
	while (i++ < len - 1)
		temp = temp->next;
	i = 0;
	while (i < len)
	{
		data->arr[i++] = *temp->data;
		temp = temp->prev;
	}
	data->len = len;
	data->index = 0;
}

void	ft_pdata_arr_down(t_d_list_header *header, int len, t_pdata *data)
{
	t_d_list	*temp;
	int			i;

	temp = header->head;
	free(data->arr);
	if (!ft_zeromalloc((void **)&data->arr, sizeof(int) * len))
		return ;
	i = 0;
	while (i < len)
	{
		data->arr[i++] = *temp->data;
		temp = temp->next;
	}
	data->len = len;
	data->index = 0;
}
