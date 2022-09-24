/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_hold.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:55:24 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/24 15:32:48 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_doubly_list.h>
#include <ft_pivot.h>
#include <ft_stack.h>

int	ft_norm_min(t_pdata *hold[3])
{
	int	min;

	min = 0;
	if (hold[1]->len != hold[1]->index && \
		hold[0]->arr[hold[0]->index] > hold[1]->arr[hold[1]->index])
	{
		min = 1;
		if (hold[2]->len != hold[2]->index && \
			hold[1]->arr[hold[1]->index] > hold[2]->arr[hold[2]->index])
			min = 2;
	}
	else if (hold[2]->len != hold[2]->index && \
		hold[0]->arr[hold[0]->index] > hold[2]->arr[hold[2]->index])
		min = 2;
	return (min);
}

int	ft_min_hold(t_pdata *hold[3])
{
	int	min;

	min = -1;
	if (hold[0]->len != hold[0]->index)
	{
		min = ft_norm_min(hold);
	}
	else if (hold[1]->len != hold[1]->index)
	{
		min = 1;
		if (hold[2]->len != hold[2]->index && \
			hold[1]->arr[hold[1]->index] > hold[2]->arr[hold[2]->index])
			min = 2;
	}
	else if (hold[2]->len != hold[2]->index)
		min = 2;
	return (min);
}

int	ft_norm_max(t_pdata *hold[3])
{
	int	max;

	max = 0;
	if (hold[1]->len != hold[1]->index && \
		hold[0]->arr[hold[0]->index] < hold[1]->arr[hold[1]->index])
	{
		max = 1;
		if (hold[2]->len != hold[2]->index && \
			hold[1]->arr[hold[1]->index] < hold[2]->arr[hold[2]->index])
			max = 2;
	}
	else if (hold[2]->len != hold[2]->index && \
		hold[0]->arr[hold[0]->index] < hold[2]->arr[hold[2]->index])
		max = 2;
	return (max);
}

int	ft_max_hold(t_pdata *hold[3])
{
	int	max;

	max = -1;
	if (hold[0]->len != hold[0]->index)
	{
		max = ft_norm_max(hold);
	}
	else if (hold[1]->len != hold[1]->index)
	{
		max = 1;
		if (hold[2]->len != hold[2]->index && \
			hold[1]->arr[hold[1]->index] < hold[2]->arr[hold[2]->index])
			max = 2;
	}
	else if (hold[2]->len != hold[2]->index)
		max = 2;
	return (max);
}

int	ft_minmax_hold(t_pivot *pivot, t_pdata *hold[3], int i)
{
	if (!pivot->arrow[i])
		return (ft_min_hold(hold));
	else
		return (ft_max_hold(hold));
}
