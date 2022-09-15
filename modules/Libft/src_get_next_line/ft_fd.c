/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:45:30 by kyoulee           #+#    #+#             */
/*   Updated: 2022/08/01 14:45:33 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_open(char *filename, int option)
{
	int		fd;

	fd = open(filename, option);
	if (fd < 0 && write(2, "fd_error\n", 8))
		exit(1);
	return (fd);
}
