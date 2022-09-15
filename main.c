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
#include <ft_push_swap.h>
#include <libft.h>
#include <ft_quick_sort.h>
#include <ft_printf_stack.h>

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

int	ft_in_list_p(t_d_list *list, int num)
{
	while (list)
	{
		if (*list->data == num)
			return (1);
		list = list->prev;
	}
	return (0);
}

int	ft_atoi_move(char **str_ptr)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while ((0x09 <= **str_ptr && **str_ptr <= 0x0D) || **str_ptr == 0x20)
		(*str_ptr)++;
	if ((**str_ptr == '-' || **str_ptr == '+'))
	{
		if (**str_ptr == '-')
			sign = -1;
		(*str_ptr)++;
	}
	while (0x30 <= **str_ptr && **str_ptr <= 0x39)
	{
		if (num > num * 10 && ft_error_m("some input is not intiger"))
			exit(0);
		num = (num * 10) + (**str_ptr - 0x30);
		(*str_ptr)++;
	}
	return (num * sign);
}

t_d_list	*ft_make_memory(int ar, char **av)
{
	t_d_list	*new;
	int			*temp;
	int			i[2];

	new = NULL;
	i[0] = 0;
	while (++i[0] < ar)
	{
		if (*av[i[0]] == 0 && ft_error_m("some input is NULL"))
			exit(0);
		i[1] = ft_atoi_len(av[i[0]]);
		while (i[1]--)
		{
			if (!ft_zeromalloc((void **)&temp, sizeof(int)))
				return (NULL);
			*temp = ft_atoi_move(&av[i[0]]);
			if (ft_in_list_p(new, *temp) && ft_error_m("same number in input"))
				exit(0);
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

	quick_sort = NULL;
	if (ft_input_error(ar, av))
		return (0);
	memory = ft_make_memory(ar, av);
	quick_sort = ft_push_swap(memory);
	ft_d_list_free(&quick_sort, free);
	return (1);
}
