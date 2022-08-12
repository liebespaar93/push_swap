/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 06:05:24 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/12 15:24:54 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <stdlib.h>
#include <libft.h>

int	ft_ra(t_d_list_header *a_ptr)
{
	if (!ft_d_list_header_add_tail(a_ptr, ft_d_list_header_pop_head(a_ptr)))
		return (0);
	return (1);
}

int	ft_rb(t_d_list_header *b_ptr)
{
	if (!ft_d_list_header_add_tail(b_ptr, ft_d_list_header_pop_head(b_ptr)))
		return (0);
	return (1);
}

int	ft_rr(t_d_list_header *a_ptr, t_d_list_header *b_ptr)
{	
	return (ft_ra(a_ptr) + ft_rb(b_ptr));
}
