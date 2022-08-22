/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 06:05:46 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 21:56:01 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <libft.h>
#include <ft_color.h>
#include <ft_printf.h>

int	ft_rra(t_d_list_header *a_ptr)
{
	if (!ft_d_list_header_add_head(a_ptr, ft_d_list_header_pop_tail(a_ptr)))
		return (0);
	ft_printf(FG_LGREEN"rra\n"NO_COLOR);
	return (1);
}

int	ft_rrb(t_d_list_header *b_ptr)
{
	if (!ft_d_list_header_add_head(b_ptr, ft_d_list_header_pop_tail(b_ptr)))
		return (0);
	ft_printf(FG_LGREEN"rrb\n"NO_COLOR);
	return (1);
}

int	ft_rrr(t_d_list_header *a_ptr, t_d_list_header *b_ptr)
{
	ft_printf(FG_LGREEN"rrr\n"NO_COLOR);
	return (ft_rra(a_ptr) + ft_rrb(b_ptr));
}
