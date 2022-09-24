/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 04:29:58 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/01 22:21:42 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_doubly_list.h>
#include <ft_push_swap.h>
#include <libft.h>
#include <ft_quick_sort.h>
#include <ft_printf.h>
#include <ft_check.h>

int	ft_input_error(int ar, char **av)
{
	char	*str;

	if (ar == 1)
		exit(0);
	while (ar-- > 1 && ft_ptrcpy((void **)&str, av[ar]))
	{
		while (*str)
		{
			if (*str == 0x20 || ft_isdigit(*str) || *str == '+' || *str == '-')
				str++;
			else if (ft_printf("Error\n"))
				exit(0);
		}
	}
	return (0);
}

int	main(int ar, char **av)
{
	t_d_list	*memory;
	t_d_list	*quick_sort;

	quick_sort = NULL;
	if (ft_input_error(ar, av))
		return (0);
	memory = ft_make_memory(ar, av);
	quick_sort = ft_check(memory);
	ft_d_list_free(&quick_sort, free);
	return (1);
}
