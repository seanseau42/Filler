# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/06/17 22:45:55 by seanseau     #+#   ##    ##    #+#        #
#    Updated: 2019/08/22 12:57:39 by seanseau    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = seanseau.filler
CC = gcc
FLAGS = -Wall -Wextra -Werror
INC = ./includes/ft_filler.h
#------------------------------------FILE--------------------------------------#

FILES = src/ft_read\
		src/ft_think\
		src/ft_play\
		src/main\

#----------------------------------SOURCE--------------------------------------#

SRC = $(addsuffix .c , $(FILES))

#-----------------------------------RULE---------------------------------------#

all: $(NAME)

$(NAME): $(SRC) $(INC)
	@make -C libft/
	@$(CC) $(FLAGS) -lft -L./libft $(SRC) -o $(NAME) -I $(INC)

clean:
	@echo "\033[1m|---------------------------------|\033[0m"
	@echo "\033[1m|------Suppression des OBJECT-----|\033[0m"
	@echo "\033[1m|---------------------------------|\033[0m"
	@make clean -C libft/

fclean: clean
	@echo "\n"
	@echo "\033[1m|---------------------------------------|\033[0m"
	@echo "\033[1m|------Suppression la libft.a-----|\033[0m"
	@echo "\033[1m|---------------------------------------|\033[0m"
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all
