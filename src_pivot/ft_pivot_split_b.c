/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot_split_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:42:04 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/24 15:38:00 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_doubly_list.h>
#include <ft_pivot.h>
#include <ft_stack.h>

void	ft_set_split_b(t_d_list_header *a, t_d_list_header *b, int len)
{
	while (len--)
		ft_pa(a, b);
}

void	ft_find_pdata_b(t_d_list_header *a, t_d_list_header *b, \
	t_pdata	*hold[3], t_pivot *pivot)
{
	hold[0] = ft_find_pdata(pivot, *b->head->data);
	hold[1] = ft_find_pdata(pivot, *b->tail->data);
	hold[2] = ft_find_pdata(pivot, *a->tail->data);
}

int	ft_for_norn_arr(t_d_list_header *a, t_pdata *hold[3], \
	t_pivot *pivot, int i)
{
	if (i < pivot->len / 3 / 3)
		ft_pdata_arr_up(a, hold[0]->len + hold[1]->len + hold[2]->len, \
			&pivot->data[i]);
	else
		ft_pdata_arr_down(a, hold[0]->len + hold[1]->len + hold[2]->len, \
			&pivot->data[i]);
	return (1);
}

void	ft_pivot_split_b(t_d_list_header *a, t_d_list_header *b, \
	t_pivot *pivot)
{
	int		i;
	int		minmax;
	t_pdata	*hold[3];

	i = 0;
	while (i++ < pivot->len / 3)
		ft_set_split_b(a, b, pivot->data[pivot->len - i].len);
	ft_find_pdata_b(a, b, hold, pivot);
	i = 0;
	while (i < pivot->len / 3)
	{
		minmax = ft_minmax_hold(pivot, hold, i);
		if (minmax == -1 && ft_for_norn_arr(a, hold, pivot, i++))
		{
			if (i >= pivot->len / 3)
				break ;
			ft_find_pdata_b(a, b, hold, pivot);
		}
		else if (minmax == 0 && ft_pa(a, b))
			hold[0]->index++;
		else if (minmax == 1 && ft_rrb(b) && ft_pa(a, b))
			hold[1]->index++;
		else if (minmax == 2 && ft_rra(a))
			hold[2]->index++;
	}
}
