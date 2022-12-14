/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:28:14 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/24 18:34:49 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <ft_doubly_list.h>

t_d_list	*ft_push_swap(t_d_list *memory);
int			*ft_result(t_d_list *memory);
int			ft_matching_result(t_d_list *list_pir, int *result);

#endif