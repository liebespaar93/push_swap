/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:31:02 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/22 21:39:35 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_quick_sort.h>
#include <libft.h>

t_d_list	*ft_quick_sort(t_d_list *memory, int max_len)
{
	t_d_list		*quick_sort;
	t_d_list_header	*a;
	t_d_list_header	*b;
	t_d_list_header	**pivot;
	int				deep;

	deep = 0;
	if (!ft_zeromalloc((void **)&pivot, sizeof(t_d_list_header *) * max_len))
		return (NULL);
	while (deep < max_len)
		if (!ft_zeromalloc((void **)&pivot[deep++], sizeof(t_d_list_header)))
			return (NULL);
	deep = 1;
	a = ft_d_list_header_init(memory);
	b = ft_d_list_header_init(NULL);
	pivot[0]->head = a->head;
	quick_sort = ft_pivot_split(a, b, pivot, deep);
	while (max_len--)
		free(pivot[max_len]);
	free(pivot);
	free(a);
	free(b);
	return (quick_sort);
}
