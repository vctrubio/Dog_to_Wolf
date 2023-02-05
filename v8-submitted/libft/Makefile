# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmendes <jmendes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 20:16:53 by rimartin          #+#    #+#              #
#    Updated: 2022/09/28 13:23:23 by jmendes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = $(wildcard ./src/*.c)

SRCBON = $(wildcard ./src_bonus/*.c)

OBJ 	= $(SRC:.c=.o)

OBJBON 	= $(SRCBON:.c=.o)

CC		= gcc -Wall -Wextra -Werror -I $(HEADER)

HEADER	= libft.h

all		: $(NAME)

$(NAME) : $(OBJ)
			ar rcs $@ $^
			ranlib $(NAME)

bonus	: $(OBJBON) $(OBJ)
			ar -rcs $(NAME) $(OBJBON) $(OBJ)

clean	:
			rm -f $(OBJ) $(OBJBON)

fclean	: clean
			rm -f $(NAME)

re		: fclean $(NAME)

rebonus	: fclean bonus

.PHONY: all clean bonus clean fclean re rebonus
