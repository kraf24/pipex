# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 19:24:08 by gpinchuk          #+#    #+#              #
#    Updated: 2022/05/31 12:55:53 by gpinchuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libft.a
src = $(wildcard *.c)
obj = $(src:.c=.o)

b_obj = $(bonus:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME):	$(obj)
	@ar rcs $(NAME) $(obj)

clean:
	@rm -rf $(obj) $(b_obj)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus