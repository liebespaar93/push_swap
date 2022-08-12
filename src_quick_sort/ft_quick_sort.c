/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:31:02 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/13 05:52:50 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_quick_sort.h>
#include <libft.h>

t_d_list	*ft_quick_sort(t_d_list *memory, int max_len)
{
	t_d_list_header	*a;
	t_d_list_header	*b;
	t_d_list_header	**pivot;
	int				deep;

	deep = 1;
	if (!ft_zeromalloc((void **)&pivot, sizeof(t_d_list_header *) * max_len))
		return (NULL);
	while (max_len--)
		if (!ft_zeromalloc((void **)&pivot[max_len], sizeof(t_d_list_header)))
			return (NULL);
	a = ft_d_list_header_init(memory);
	b = ft_d_list_header_init(NULL);
	pivot[0]->head = a->head;
	return (ft_pivot_split(a, b, pivot, deep));
}
