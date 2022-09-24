/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:18:29 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/01 22:37:59 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_check.h>
#include <ft_push_swap.h>
#include <ft_quick_sort.h>
#include <libft.h>
#include <ft_doubly_list.h>
#include <ft_printf.h>
#include <ft_get_next_line.h>
#include <ft_color.h>

void	ft_stack_change(t_d_list_header *a, t_d_list_header *b, \
	char *str)
{
	if (ft_memcmp(str, "sa\n", 3) == 0)
		ft_sa(a);
	else if (ft_memcmp(str, "sb\n", 3) == 0)
		ft_sb(b);
	else if (ft_memcmp(str, "ss\n", 3) == 0)
		ft_ss(a, b);
	else if (ft_memcmp(str, "pa\n", 3) == 0)
		ft_pa(a, b);
	else if (ft_memcmp(str, "pb\n", 3) == 0)
		ft_pb(a, b);
	else if (ft_memcmp(str, "ra\n", 3) == 0)
		ft_ra(a);
	else if (ft_memcmp(str, "rb\n", 3) == 0)
		ft_rb(b);
	else if (ft_memcmp(str, "rr\n", 3) == 0)
		ft_rr(a, b);
	else if (ft_memcmp(str, "rra\n", 4) == 0)
		ft_rra(a);
	else if (ft_memcmp(str, "rrb\n", 4) == 0)
		ft_rrb(b);
	else if (ft_memcmp(str, "rrr\n", 4) == 0)
		ft_rrr(a, b);
}

void	ft_check_stack(t_d_list_header *a, t_d_list_header *b, \
	t_result *result, t_pivot *pivot)
{
	char	*str;

	while (1)
	{
		result->p = 0;
		str = ft_get_next_line(0);
		if (str)
			ft_stack_change(a, b, str);
		else if (ft_printf(FG_LRED"KO\n"NO_COLOR))
			break ;
		free(str);
		ft_matching_result(a->head, result, pivot);
		if (result->p == result->index && ft_printf(FG_GREEN"OK\n"NO_COLOR))
			break ;
	}
}

t_d_list	*ft_check(t_d_list *memory)
{
	t_d_list_header	*a;
	t_d_list_header	*b;
	t_pivot			*pivot;
	t_result		*result;

	if (!memory)
		return (NULL);
	a = ft_d_list_header_init(memory);
	b = ft_d_list_header_init(NULL);
	pivot = ft_pivot_new(NULL, NULL);
	result = ft_make_result(memory);
	ft_quick_sort(result->result, 0, result->index - 1);
	ft_check_stack(a, b, result, pivot);
	free(result->result);
	free(result);
	free(pivot);
	free(a);
	free(b);
	return (memory);
}
