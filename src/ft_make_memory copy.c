/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:04:23 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/24 14:26:19 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_doubly_list.h>
#include <libft.h>
#include <ft_math.h>

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

int	ft_atoi_push_swap(char *str_ptr)
{
	long	num;
	long	sign;

	num = 0;
	sign = 0;
	if ((*str_ptr == '-' || *str_ptr == '+'))
	{
		if (*str_ptr == '-')
			sign = -1;
		str_ptr++;
	}
	if (!(0x30 <= *str_ptr && *str_ptr <= 0x39) && ft_error_m("input error"))
		exit(1);
	while (0x30 <= *str_ptr && *str_ptr <= 0x39)
	{
		if (num * 10 + (*str_ptr - 0x30) > 0x7FFFFFFF - sign && \
			ft_error_m("some input is not intiger"))
			exit(1);
		num = (num * 10) + (*str_ptr - 0x30);
		str_ptr++;
	}
	if (*str_ptr != 0 && ft_error_m("some input is not intiger"))
		exit(1);
	return (num * ft_sign(sign));
}

int	*ft_split_atoi(char *str, char c)
{
	int		*split_int;
	char	**split;
	int		index;
	int		i;

	split = ft_split(str, c);
	index = ft_split_len(str, c);
	if (!ft_zeromalloc((void **)&split_int, index * sizeof(int)))
	{
		free(split);
		return (NULL);
	}
	i = 0;
	while (i < index)
	{
		split_int[i] = ft_atoi_push_swap(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (split_int);
}

void	ft_memory_write(t_d_list *new, int *split_atoi, int i[3])
{
	int	*temp;

	i[2] = 0;
	while (i[2] < i[1])
	{
		if (!ft_zeromalloc((void **)&temp, sizeof(int)))
			;
		if (ft_in_list_p(new, split_atoi[i[2]]) \
			&& ft_error_m("same number in input"))
			exit(0);
		*temp = split_atoi[i[2]];
		new = ft_d_list_add_next(new, ft_d_list_new(temp));
		i[2]++;
	}	
}

t_d_list	*ft_make_memory(int ar, char **av)
{
	t_d_list	*new;
	int			i[3];
	int			*split_atoi;
	int			*temp;

	new = NULL;
	i[0] = 0;
	while (++i[0] < ar)
	{
		if (*av[i[0]] == 0 && ft_error_m("some input is NULL"))
			exit(0);
		i[1] = ft_split_len(av[i[0]], ' ');
		split_atoi = ft_split_atoi(av[i[0]], ' ');
		ft_memory_write(new, split_atoi, *i);
		free(split_atoi);
	}
	while (new->prev)
		new = new->prev;
	return (new);
}
