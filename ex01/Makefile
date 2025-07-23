CC = g++
CFLAGS =  -std=c++98 -Wall -Wextra -Werror

SRC_FILES = main.cpp Contact.cpp \
PhoneBookAdd.cpp \
PhoneBookSearch.cpp \
PhoneBookDisplayAll.cpp \
PhoneBookDisplayByIndex.cpp 

OBJ_FILES = $(SRC_FILES:.cpp=.o)
NAME = contactManager

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
