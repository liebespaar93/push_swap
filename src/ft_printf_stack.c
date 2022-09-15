/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:38:31 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/01 19:22:57 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_doubly_list.h>
#include <ft_color.h>
#include <ft_printf.h>
#include <ft_quick_sort.h>

int	ft_printf_stack(t_d_list *d_list, t_pivot *pivot, char *str)
{
	t_d_list	*stack;

	if (ft_printf(FG_CYAN"%s \t\n\n", str) && !d_list)
		return (ft_printf("\e[100m NULL \e[0m\n\n"));
	stack = d_list;
	while (stack && ft_printf(BG_DGREY""))
	{
		if (pivot && pivot->a_hold && pivot->a_hold->data == stack->data)
			ft_printf(BG_LYELLOW"");
		else if (pivot && pivot->head && pivot->head->data == stack->data)
			ft_printf(BG_BLUE"");
		else if (pivot && pivot->b_hold && pivot->b_hold->data == stack->data)
			ft_printf(BG_LMAGENTA"");
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
