# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giabanji <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 13:16:49 by giabanji          #+#    #+#              #
#    Updated: 2018/02/23 16:49:50 by giabanji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = giabanji.filler

SRC = main.c ft_readmap.c check_func.c ft_insert.c best_insert.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	cd libft/ && $(MAKE)
	gcc $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a
	
%.o:%.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
		make fclean -C libft/
		rm -f $(NAME)

re: clean all
