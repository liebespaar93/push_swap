/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 06:06:22 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/12 15:24:33 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <libft.h>

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
	return (1);
}

int	ft_ss(t_d_list_header *a_ptr, t_d_list_header *b_ptr)
{
	return (ft_sa(a_ptr) + ft_sa(b_ptr));
}
