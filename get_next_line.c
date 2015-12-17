/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 22:12:58 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/18 00:57:32 by ddela-cr         ###   ########.fr       */
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
			return (1);
		if (ft_append(fd, &(tmp->overflow), &ret) == -1)
			return (-1);
		if (ret == 0 && ft_strlen(tmp->overflow))
		{
			*line = ft_strdup(tmp->overflow);
			ft_bzero(tmp->overflow, ft_strlen(tmp->overflow));
			return (1);
		}
	}
	free(tmp->overflow);
	tmp->overflow = NULL;
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

void		ft_check_fd(t_list **list, t_list **tmp, int fd)
{
	*tmp = *list;
	while (*tmp)
	{
		if ((*tmp)->fd == fd)
			break ;
		*tmp = (*tmp)->next;
	}
	if (!*tmp)
	{
		t_list		*new;

		new = (t_list *)malloc(sizeof(t_list));
		new->fd = fd;
		new->next = *list;
		*list = new;
		*tmp = *list;
	}
}
