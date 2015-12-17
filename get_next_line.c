/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 22:12:58 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/17 01:18:03 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "libft/libft.h"
#include "get_next_line.h"

int			get_next_line(int const fd, char **line)
{
	static char		*tmp[MAX_FD];
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	ret = BUFF_SIZE;
	while (ret > 0 || ft_strlen(tmp[fd]))
	{
		if ((ft_store_line(&tmp[fd], line)) == 1)
			return (1);
		if (ft_append(fd, &tmp[fd], &ret) == -1)
			return (-1);
		if (ret == 0 && ft_strlen(tmp[fd]))
		{
			*line = ft_strdup(tmp[fd]);
			ft_bzero(tmp[fd], ft_strlen(tmp[fd]));
			return (1);
		}
	}
	free(tmp[fd]);
	tmp[fd] = NULL;
	return (0);
}

int			ft_store_line(char **tmp, char **line)
{
	char			*str;

	if ((str = ft_strchr(*tmp, '\n')))
	{
		*str = '\0';
		*line = ft_strdup(*tmp);
		ft_memmove(*tmp, str + 1, ft_strlen(str + 1) + 1);
		return (1);
	}
	return (0);
}

int			ft_append(int const fd, char **tmp, int *ret)
{
	char			*buf;

	buf = ft_strnew(BUFF_SIZE);
	if ((*ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	if (*tmp == '\0')
		*tmp = ft_strnew(0);
	buf[*ret] = '\0';
	*tmp = ft_strjoin(*tmp, buf);
	free(buf);
	return (0);
}
