/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta <ccosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 19:32:43 by ccosta            #+#    #+#             */
/*   Updated: 2016/01/28 06:46:38 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		lol;

	line = NULL;
	fd = open("get_next_line.h", O_RDONLY);
	while ((lol = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	printf("%d", lol);
	return (0);
}
