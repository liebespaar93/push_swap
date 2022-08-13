/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:28:14 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/13 07:18:29 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <ft_doubly_list.h>

int	ft_sa(t_d_list_header *a_ptr);
int	ft_sb(t_d_list_header *b_ptr);
int	ft_ss(t_d_list_header *a_ptr, t_d_list_header *b_ptr);

int	ft_pa(t_d_list_header *a_ptr, t_d_list_header *b_ptr);
int	ft_pb(t_d_list_header *a_ptr, t_d_list_header *b_ptr);

int	ft_ra(t_d_list_header *a_ptr);
int	ft_rb(t_d_list_header *b_ptr);
int	ft_rr(t_d_list_header *a_ptr, t_d_list_header *b_ptr);

int	ft_rra(t_d_list_header *a_ptr);
int	ft_rrb(t_d_list_header *b_ptr);
int	ft_rrr(t_d_list_header *a_ptr, t_d_list_header *b_ptr);

#endif