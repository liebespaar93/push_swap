/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 04:29:58 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/25 09:29:08 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_doubly_list.h>
#include <ft_push_swap.h>
#include <libft.h>
#include <ft_quick_sort.h>
#include <ft_printf.h>
#include <ft_printf_stack.h>

int	ft_input_error(int ar, char **av, int (*f)(int))
{
	char	*str;

	if (ar == 1 && ft_error_m("input nothing"))
		exit(0);
	while (ar-- > 1 && ft_ptrcpy((void **)&str, av[ar]))
		while (*str)
			if (!f(*str++) && ft_error_m("some input is not integer"))
				exit(0);
	return (0);
}

t_d_list	*ft_make_memory(int ar, char **av)
{
	t_d_list	*new;
	int			*temp;

	new = NULL;
	while (1 < ar--)
	{
		temp = (int *)malloc(sizeof(int));
		if (!temp)
			(ft_d_list_free(&new, free));
		if (*av[ar] == NULL && ft_error_m("some input is NULL"))
			exit(0);
		*temp = ft_atoi(av[ar]);
		new = ft_d_list_add_prev(new, ft_d_list_new(temp));
	}
	return (new);
}

int	main(int ar, char **av)
{
	t_d_list	*memory;
	t_d_list	*quick_sort;

	if (ft_input_error(ar, av, ft_isdigit))
		return (0);
	memory = ft_make_memory(ar, av);
	quick_sort = ft_quick_sort(memory, ar + 1);
	ft_d_list_free(&quick_sort, free);
	return (1);
}
