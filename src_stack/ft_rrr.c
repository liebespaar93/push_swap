/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 06:05:46 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/25 09:28:05 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <ft_doubly_list.h>

int	ft_rra(t_d_list_header *a_ptr)
{
	if (!ft_d_list_header_add_head(a_ptr, ft_d_list_header_pop_tail(a_ptr)))
		return (0);
	ft_printf("rra\n");
	return (1);
}

int	ft_rrb(t_d_list_header *b_ptr)
{
	if (!ft_d_list_header_add_head(b_ptr, ft_d_list_header_pop_tail(b_ptr)))
		return (0);
	ft_printf("rrb\n");
	return (1);
}

int	ft_rrr(t_d_list_header *a_ptr, t_d_list_header *b_ptr)
{
	ft_printf("rrr\n");
	return (ft_rra(a_ptr) + ft_rrb(b_ptr));
}
