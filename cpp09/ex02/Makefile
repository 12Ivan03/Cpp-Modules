
CXX = c++
CXXFLAGS =  -std=c++11 -Wall -Wextra -Werror -g3

SRC_FILES = main.cpp PmergeMe.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o)
NAME = PmergeMe

all: $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	@$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)

clean:
	@rm -rf $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
