# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddela-cr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:43:54 by ddela-cr          #+#    #+#              #
#    Updated: 2016/01/04 17:55:25 by ddela-cr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

OBJS_PATH = objs/

SRCS		=	ft_bzero.c\
ft_memset.c\
ft_memcpy.c\
ft_memmove.c\
ft_memchr.c\
ft_strlen.c\
ft_strdup.c\
ft_strchr.c\
ft_strnew.c\
ft_strjoin.c

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c $(SRCS) $(FLAGS) -I includes
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@mkdir $(OBJS_PATH)
	@mv $(OBJS) $(OBJS_PATH)
	@echo "\033[32mCreated libft.a\033[0m"

clean:
	@rm -rf $(OBJS_PATH)
	@echo "\033[31mRemoved .o files\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mRemoved libft.a\033[0m"

re: fclean all

.PHONY: all clean fclean re
