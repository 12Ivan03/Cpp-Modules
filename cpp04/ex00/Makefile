
CC = c++
CFLAGS =  -std=c++98 -Wall -Wextra -Werror -g

SRC_FILES = main.cpp Animal.cpp Cat.cpp Dog.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o)
NAME = polynmorphism

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
