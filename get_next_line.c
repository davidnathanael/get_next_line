/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 22:12:58 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/29 12:56:44 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "libft/libft.h"
#include "get_next_line.h"

int			get_next_line(int const fd, char **line)
{
	static t_list		*list;
	t_list				*tmp;
	int					ret;

	if (fd < 0 || !line)
		return (-1);
	ft_check_fd(&list, &tmp, fd);
	ret = BUFF_SIZE;
	while (ret > 0 || ft_strlen(tmp->overflow))
	{
		if ((ft_store_line(&(tmp->overflow), line)) == 1)
			return (READ);
		if (ft_append(fd, &(tmp->overflow), &ret) == -1)
			return (ERROR);
		if (ret == 0 && ft_strlen(tmp->overflow))
		{
			*line = ft_strdup(tmp->overflow);
			ft_bzero(tmp->overflow, ft_strlen(tmp->overflow));
			return (READ);
		}
	}
	free(tmp->overflow);
	tmp->overflow = NULL;
	return (END);
}

int			ft_store_line(char **overflow, char **line)
{
	char			*str;

	if ((str = ft_strchr(*overflow, '\n')))
	{
		*str = '\0';
		*line = ft_strdup(*overflow);
		ft_memmove(*overflow, str + 1, ft_strlen(str + 1) + 1);
		return (1);
	}
	return (0);
}

int			ft_append(int const fd, char **overflow, int *ret)
{
	char			*buf;

	buf = ft_strnew(BUFF_SIZE);
	if ((*ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	if (*overflow == '\0')
		*overflow = ft_strnew(0);
	buf[*ret] = '\0';
	*overflow = ft_strjoin(*overflow, buf);
	free(buf);
	return (0);
}

void		ft_check_fd(t_list **list, t_list **overflow, int fd)
{
	t_list		*new;

	*overflow = *list;
	while (*overflow)
	{
		if ((*overflow)->fd == fd)
			break ;
		*overflow = (*overflow)->next;
	}
	if (!*overflow)
	{
		new = (t_list *)malloc(sizeof(t_list));
		new->fd = fd;
		new->overflow = ft_strnew(0);
		new->next = *list;
		*list = new;
		*overflow = *list;
	}
}
