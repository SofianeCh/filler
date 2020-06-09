# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sofchami <sofchami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 20:56:30 by sofchami          #+#    #+#              #
#    Updated: 2019/03/18 17:48:04 by sofchami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sofchami.filler
CFLGS = -Wall -Werror -Wextra
SRC = filler.c strategy.c check.c creamap.c init.c dir_t.c dir_l.c dir_breche.c
INC = libft/libft.a
INC2 = src/filler.h
Green=\033[0;32m
NC=\033[0m

SRCD = $(addprefix src/,$(SRC))
OBJ = $(subst .c,.o,$(SRC))

.PHONY: clean fclean re all

$(NAME):
	@make re -C libft
	@gcc -c $(SRCD) $(INC2) $(CFLGS)
	@gcc -o $(NAME) $(OBJ) $(INC)
	@echo "${Green}Compilation Succesfull${NC} "

all: $(NAME)

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "${Green}Cleaning succesfull${NC} "

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "${Green}FCleaning succesfull${NC} "

re: fclean all
