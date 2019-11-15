# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/05 22:15:16 by aboukhri          #+#    #+#              #
#    Updated: 2019/11/10 15:38:07 by aboukhri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=libft.a
SRC=convert_binary.c err_putchar.c ft_atoi.c ft_bzero.c ft_chrlen.c ft_chrlen_quote.c ft_dbl_strdel.c ft_dbl_strdup.c ft_dbl_strlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_itoa_base.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_power.c ft_put_dblstr.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_realloc.c ft_realloc_double.c ft_remalloc.c ft_strcat.c ft_strchr.c ft_strchr_quote.c ft_strchrindex.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strdupfree.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strjoinfree.c ft_strlcat.c ft_strlen.c ft_strlower.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrchrindex.c ft_strrdel.c ft_strrev.c ft_strsplit.c ft_strsplit_quote.c ft_strstr.c ft_strstrindex.c ft_strsub.c ft_strtrim.c ft_strtrim_quote.c ft_strupper.c ft_tolower.c ft_toupper.c ft_utoa.c str_isalnum.c exit_program.c is_str_number.c garbage_mem.c free_garbage.c ft_chrcount.c ft_str_isnum.c int_putchar.c ft_strline.c ft_strjoinf.c ft_putstr_str.c
OBJDIR=objs

OBJ = $(SRC:.c=.o)
OBJPATH = $(addprefix objs/, $(OBJ))
FLAG=-Wall -Wextra -Werror
INCLUDE=libft.h

all: $(NAME)

$(NAME) : $(OBJPATH) $(INCLUDE)
	ar rc $(NAME) $(OBJPATH)

$(OBJPATH): objs/%.o : %.c | $(OBJDIR)
	gcc $(FLAG) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
fclean: clean
	@rm -f $(NAME)
re: fclean all
