/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 04:29:58 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/01 22:21:53 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_doubly_list.h>
#include <libft.h>
#include <ft_push_swap.h>
#include <ft_memory.h>

int	ft_input_error(int ar, char **av)
{
	char	*str;

	if (ar == 1 && ft_warring_m("input nothing"))
		exit(0);
	while (ar-- > 1 && ft_ptrcpy((void **)&str, av[ar]))
	{
		while (*str)
		{
			if (*str == 0x20 || ft_isdigit(*str) || *str == '+' || *str == '-')
				str++;
			else if (ft_error_m("input digit only"))
				exit(0);
		}
	}
	return (0);
}

int	main(int ar, char **av)
{
	t_d_list	*memory;

	if (ft_input_error(ar, av))
		return (0);
	memory = ft_make_memory(ar, av);
	memory = ft_push_swap(memory);
	return (1);
}
