# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddela-cr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:43:54 by ddela-cr          #+#    #+#              #
#    Updated: 2015/12/17 01:22:53 by ddela-cr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

SRC_C		=	ft_bzero.c\
ft_memset.c\
ft_memcpy.c\
ft_memmove.c\
ft_memchr.c\
ft_strlen.c\
ft_strdup.c\
ft_strchr.c\
ft_strnew.c\
ft_strjoin.c

SRC_O		=	$(SRC_C:.c=.o)

all:		$(NAME)

$(NAME): $(SRC_O)
	ar rc $(NAME) $(SRC_O)
	ranlib $(NAME)

clean:
	rm -f $(SRC_O)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		fclean clean re
