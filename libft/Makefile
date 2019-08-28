# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataleb <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/05 16:47:33 by ataleb            #+#    #+#              #
#    Updated: 2018/10/05 17:07:06 by ataleb           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
SRC = $(wildcard *.c)
all : $(NAME)
$(NAME):
	$(CC) -Wextra -Wall -Werror -c $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)
clean:
	/bin/rm -f $(wildcard *.o)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
