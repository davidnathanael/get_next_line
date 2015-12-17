/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:29:09 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/17 00:51:25 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft/libft.h"

int main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*line;

	line = NULL;
	ret = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("open() failed.\n");
			return (1);
		}
		while ((ret = get_next_line(fd, &line)))
		{
			printf("line : '%s' | get_next_line : %d\n----------------------------\n", line, ret);
		}
		printf("get_next_line : %d\n----------------------------\n", ret);
	}
	else
		ft_putstr("usage : gnl <file>\n");
	return (0);
}
