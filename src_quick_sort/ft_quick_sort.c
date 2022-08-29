/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:31:02 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/27 18:04:04 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_quick_sort.h>
#include <libft.h>

t_d_list	*ft_quick_sort(t_d_list *memory)
{
	t_d_list		*quick_sort;
	t_d_list_header	*a;
	t_d_list_header	*b;
	t_pivot			*pivot;
	
	a = ft_d_list_header_init(memory);
	b = ft_d_list_header_init(NULL);
	pivot = ft_pivot_new(NULL, NULL);
	quick_sort = ft_pivot_split(a, b, pivot);
	free(pivot);
	free(a);
	free(b);
	return (quick_sort);
}
