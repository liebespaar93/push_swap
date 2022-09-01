/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:28:14 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/01 20:24:09 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <ft_doubly_list.h>

typedef struct s_pivot	t_pivot;

typedef struct s_pivot
{
	t_d_list	*head;
	t_d_list	*tail;
	t_d_list	*a_hold;
	t_d_list	*b_hold;
	t_pivot		*prev;
	int			deep;
}	t_pivot;

typedef struct s_result
{
	int				*result;
	unsigned int	index;
	unsigned int	p;
	unsigned int	last;
}	t_result;

t_result	*ft_make_result(t_d_list *memory);
t_d_list	*ft_push_swap(t_d_list *memory);

int			ft_sa(t_d_list_header *a_ptr);
int			ft_sb(t_d_list_header *b_ptr);
int			ft_ss(t_d_list_header *a_ptr, t_d_list_header *b_ptr);

int			ft_pa(t_d_list_header *a_ptr, t_d_list_header *b_ptr);
int			ft_pb(t_d_list_header *a_ptr, t_d_list_header *b_ptr);

int			ft_ra(t_d_list_header *a_ptr);
int			ft_rb(t_d_list_header *b_ptr);
int			ft_rr(t_d_list_header *a_ptr, t_d_list_header *b_ptr);

int			ft_rra(t_d_list_header *a_ptr);
int			ft_rrb(t_d_list_header *b_ptr);
int			ft_rrr(t_d_list_header *a_ptr, t_d_list_header *b_ptr);

#endif