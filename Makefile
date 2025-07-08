# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocubukcu <ocubukcu@student.42kocaeli.com.t +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 19:51:44 by ocubukcu          #+#    #+#              #
#    Updated: 2024/12/18 06:34:23 by ocubukcu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	utilities.c \
		pipex.c
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM	=	rm -f
NAME = pipex
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make all -C libft
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)


fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(OBJ)
	make clean -C libft

re : fclean all

.PHONY: re fclean clean all