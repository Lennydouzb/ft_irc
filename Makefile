CXX=c++
CXXFLAGS = -Wall -Werror -Wextra -g -std=c++98
NAME = ircserv
SRC_DIR = ./srcs/
SRCS = main.cpp \
	$(SRC_DIR)Irc.cpp \
	$(SRC_DIR)User.cpp \
	$(SRC_DIR)Channel.cpp \
	$(SRC_DIR)parser/Parser.cpp \
	$(SRC_DIR)parser/ACommand.cpp \
	$(SRC_DIR)parser/commands/CapCommand.cpp \
	$(SRC_DIR)parser/commands/JoinCommand.cpp \
	$(SRC_DIR)parser/commands/KickCommand.cpp \
	$(SRC_DIR)parser/commands/ModeCommand.cpp \
	$(SRC_DIR)parser/commands/NickCommand.cpp \
	$(SRC_DIR)parser/commands/PassCommand.cpp \
	$(SRC_DIR)parser/commands/PingCommand.cpp \
	$(SRC_DIR)parser/commands/PrivmsgCommand.cpp \
	$(SRC_DIR)parser/commands/QuitCommand.cpp \
	$(SRC_DIR)parser/commands/TopicCommand.cpp \
	$(SRC_DIR)parser/commands/UserCommand.cpp

OBJ_DIR = .build/
OBJS = $(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all fclean clean re
