# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/18 11:07:25 by ipavlov           #+#    #+#              #
#    Updated: 2025/08/18 11:56:50 by ipavlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS =  -std=c++98 -Wall -Wextra -Werror

SRC_FILES = main.cpp \
Zombie.cpp \
zombieHorde.cpp \
error_handler.cpp \
utils.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o)
NAME = moar_brainz

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

clean:
	@rm -rf $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
