/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 06:06:22 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/01 16:05:06 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <libft.h>
#include <ft_color.h>
#include <ft_printf.h>

int	ft_sa(t_d_list_header *a_ptr)
{
	t_d_list	*pop1;
	t_d_list	*pop2;

	if (!a_ptr->head && !a_ptr->head->next && ft_error_m("need 2 node!"))
		return (0);
	pop1 = ft_d_list_header_pop_head(a_ptr);
	pop2 = ft_d_list_header_pop_head(a_ptr);
	ft_d_list_header_add_head(a_ptr, pop1);
	ft_d_list_header_add_head(a_ptr, pop2);
	ft_printf("sa\n");
	return (1);
}

int	ft_sb(t_d_list_header *b_ptr)
{
	t_d_list	*pop1;
	t_d_list	*pop2;

	if (!b_ptr->head && !b_ptr->head->next && ft_error_m("need 2 node!"))
		return (0);
	pop1 = ft_d_list_header_pop_head(b_ptr);
	pop2 = ft_d_list_header_pop_head(b_ptr);
	ft_d_list_header_add_head(b_ptr, pop1);
	ft_d_list_header_add_head(b_ptr, pop2);
	ft_printf("sb\n");
	return (1);
}

int	ft_ss(t_d_list_header *a_ptr, t_d_list_header *b_ptr)
{
	ft_printf("ss\n");
	return (ft_sa(a_ptr) + ft_sa(b_ptr));
}
