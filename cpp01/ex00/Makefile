# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipavlov <ipavlov@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/18 10:58:10 by ipavlov           #+#    #+#              #
#    Updated: 2025/08/18 10:58:55 by ipavlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS =  -std=c++98 -Wall -Wextra -Werror -g

SRC_FILES = main.cpp \
Zombie.cpp \
newZombie.cpp\
randomChump.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o)
NAME = BraiiiiiiinnnzzzZ

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
