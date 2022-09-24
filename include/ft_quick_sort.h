/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:43:09 by kyoulee           #+#    #+#             */
/*   Updated: 2022/09/24 15:41:21 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUICK_SORT_H
# define FT_QUICK_SORT_H

void	ft_swap(int *array, int i, int j);
int		ft_partition(int *array, int left, int right);
void	ft_quick_sort(int *array, int left, int right);

#endif