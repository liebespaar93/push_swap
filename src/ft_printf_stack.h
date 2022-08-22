/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stack.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:18:31 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 21:47:41 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STACK_H
# define FT_PRINTF_STACK_H

# include <ft_doubly_list.h>

int		ft_printf_stack(t_d_list *d_list, t_d_list_header **pivot, \
	char *str);
void	ft_printf_ab(t_d_list_header *a, t_d_list_header *b, \
	t_d_list_header **pivot);

#endif
