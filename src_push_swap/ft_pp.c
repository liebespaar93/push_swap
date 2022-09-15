/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 03:37:41 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/25 09:27:38 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <libft.h>
#include <ft_printf.h>
#include <ft_color.h>

int	ft_pa(t_d_list_header *a_ptr, t_d_list_header *b_ptr)
{
	if (!ft_d_list_header_add_head(a_ptr, ft_d_list_header_pop_head(b_ptr)))
		return (0);
	ft_printf("pa\n");
	return (1);
}

int	ft_pb(t_d_list_header *a_ptr, t_d_list_header *b_ptr)
{
	if (!ft_d_list_header_add_head(b_ptr, ft_d_list_header_pop_head(a_ptr)))
		return (0);
	ft_printf("pb\n");
	return (1);
}
