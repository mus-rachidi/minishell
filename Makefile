# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: murachid <murachid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 13:27:28 by rel-bour          #+#    #+#              #
#    Updated: 2021/12/11 01:45:59 by murachid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc  -lreadline -ledit -g -L /goinfre/murachid/.brew/opt/readline/lib -I /goinfre/murachid/.brew/opt/readline/include
CFLAGS = -Wall -Wextra -Werror   

SRC = main.c\
executing/*.c\
executing/hashmap/*.c\
libft/*.c\
parsing/*.c\

all : $(NAME) 

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC)  -o $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

ref:	fclean fs
