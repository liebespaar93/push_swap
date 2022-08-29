/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:38:31 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/28 13:30:52 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_doubly_list.h>
#include <ft_color.h>
#include <ft_printf.h>
#include <ft_quick_sort.h>

int	ft_printf_stack(t_d_list *d_list, t_pivot *pivot, char *str)
{
	t_d_list	*stack;
	t_pivot		*temp;
	size_t		i;

	if (ft_printf(FG_CYAN"%s \t\n\n", str) && !d_list)
		return (ft_printf("\e[100m NULL \e[0m\n\n"));
	stack = d_list;
	while (stack && ft_printf(BG_DGREY""))
	{
		i = 0;
		temp = pivot;
		while (temp)
		{
			if (temp->head == stack && i++)
			{
				if (i == 1)
					ft_printf(BG_LYELLOW"");
				else if (i == 2)
					ft_printf(BG_LMAGENTA"");
				else
					ft_printf(BG_LBLUE"");
			}
			temp = temp->prev;
		}
		ft_printf("  %d  "NO_COLOR"\t", *(int *)stack->data);
		stack = stack->next;
	}
	return (ft_printf("\n\n"));
}

void	ft_printf_ab(t_d_list_header *a, t_d_list_header *b, \
	t_pivot *pivot)
{
	ft_printf("\n ===================================\n");
	if (a)
		ft_printf_stack(a->head, pivot, "a : ");
	if (b)
		ft_printf_stack(b->head, pivot, "b : ");
	ft_printf(" ===================================\n");
}
