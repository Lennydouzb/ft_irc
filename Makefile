CXX=c++
CXXFLAGS = -Wall -Werror -Wextra -g -std=c++98
NAME = ircserv
SRC_DIR = ./srcs/
SRCS = main.cpp \
	$(SRC_DIR)Irc.cpp \
	$(SRC_DIR)User.cpp \
	$(SRC_DIR)parser/Parser.cpp \

OBJ_DIR = .build/
OBJS = $(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@mkdir -p .build/parser
	$(CXX) $(CXXFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all fclean clean re
