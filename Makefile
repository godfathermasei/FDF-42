#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 14:56:17 by mmasyush          #+#    #+#              #
#    Updated: 2018/12/02 14:56:18 by mmasyush         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = ./src/main.c \
		./src/read.c \
		./src/write.c \
		./src/keys.c	\
		./src/count_point.c \
		./src/change.c 

OUT = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OUT)
	make -C ./libft
	gcc $(FLAGS) -o $(NAME) $(OUT) $(MLX) ./libft/libft.a
	@echo 'Compilated!'

clean:
	rm -f $(OUT)
	make -C ./libft clean

fclean: clean 
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all
