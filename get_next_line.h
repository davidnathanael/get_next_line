/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 22:13:20 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/17 01:15:06 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 9999
# define MAX_FD 1028

int		get_next_line(int const fd, char **line);
int		ft_store_line(char **tmp, char **line);
int		ft_append(int const fd, char **tmp, int *ret);

#endif
