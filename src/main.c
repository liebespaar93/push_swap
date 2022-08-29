/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 04:29:58 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/27 21:21:56 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_doubly_list.h>
#include <ft_push_swap.h>
#include <libft.h>
#include <ft_quick_sort.h>
#include <ft_printf_stack.h>

int	ft_input_error(int ar, char **av)
{
	char	*str;

	if (ar == 1 && ft_error_m("input nothing"))
		exit(0);
	while (ar-- > 1 && ft_ptrcpy((void **)&str, av[ar]))
	{
		while (*str)
		{
			if (*str == 0x20 || ft_isdigit(*str))
				str++;
			else
				exit(0);
		}
	}
	return (0);
}

t_d_list	*ft_make_memory(int ar, char **av)
{
	t_d_list	*new;
	char		*string;
	int			*temp;
	int			i[2];

	new = NULL;
	i[0] = 0;
	while (++i[0] < ar)
	{
		if (*av[i[0]] == 0 && ft_error_m("some input is NULL"))
			exit(0);
		string = av[i[0]];
		i[1] = ft_atoi_len(av[i[0]]);
		while (i[1]--)
		{
			if (!ft_zeromalloc((void **)&temp, sizeof(int)))
				exit(0);
			*temp = ft_atoi_move(&string);
			new = ft_d_list_add_next(new, ft_d_list_new(temp));
		}
	}
	while (new->prev)
		new = new->prev;
	return (new);
}

int	main(int ar, char **av)
{
	t_d_list	*memory;
	t_d_list	*quick_sort;

	if (ft_input_error(ar, av))
		return (0);
	memory = ft_make_memory(ar, av);
	ft_printf_stack(memory, 0, "memory");
	quick_sort = ft_quick_sort(memory);
	ft_printf_stack(quick_sort, 0, "quick_sort");
	ft_d_list_free(&quick_sort, free);
	return (1);
}
