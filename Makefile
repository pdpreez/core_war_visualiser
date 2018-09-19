# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppreez <marvin@42.FR>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/17 09:23:32 by ppreez            #+#    #+#              #
#    Updated: 2018/09/17 17:33:47 by ppreez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = core_war_visualiser

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
LIB_PATH = ./libft/

SRC_FILE = main.c
			
OBJ_FILE = $(SRC_FILE:%.c=%.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILE))

CCFLAGS = -Wall -Wextra -Werror -I.
NCURSES = -lncurses -lpanel
CC = gcc $(CCFLAGS)

LIBF = $(LIB_PATH)libft.a

all: $(NAME) $(LIBF)

$(NAME): $(OBJ) $(COMPILE)
	make -C ./libft/
	$(CC) $(NCURSES) -o $@ $(LIBF) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) -I$(INC_PATH) -o $@ -c $<

clean: cleanlib
	/bin/rm -rf $(OBJ)

fclean: clean fcleanlib
	/bin/rm $(NAME)

cleanlib:
	make clean -C$(LIB_PATH)
	
fcleanlib:
	make fclean -C $(LIB_PATH)

re: fclean all

.PHONY: re fclean clean all