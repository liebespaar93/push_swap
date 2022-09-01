/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:31:02 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/01 19:39:51 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_quick_sort.h>
#include <libft.h>

void	ft_swap(int *array, int i, int j)
{
	int	temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

int	ft_partition(int *array, int left, int right)
{
	int	pivot;
	int	temp;

	temp = left;
	pivot = array[left];
	while (left < right)
	{
		while (pivot < array[right])
			right--;
		while (left < right && pivot >= array[left])
			left++;
		ft_swap(array, left, right);
	}
	array[temp] = array[left];
	array[left] = pivot;
	return (left);
}

void	ft_quick_sort(int *array, int left, int right)
{
	int	pivot;

	if (left >= right)
		return ;
	pivot = ft_partition(array, left, right);
	ft_quick_sort(array, left, pivot - 1);
	ft_quick_sort(array, pivot + 1, right);
}
