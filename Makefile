NAME		= containers
CPPFLAGS	= -MMD -Wall -Wextra -Werror -std=c++98
#-MMD : first M for dependencies, second M to ignore system header directories, D to output to file .d with same name as .o file
CPP			= c++

SRC_DIR		= ./src
HEADER_DIR	= ./inc
OBJ_DIR		= ./obj
INC			= -I $(HEADER_DIR)

SRC_LIST	= main.cpp
HEADER_LIST	= vector.hpp vector.tpp

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_LIST))
HEADERS		= $(addprefix $(HEADER_DIR)/, $(HEADER_LIST))
OBJS		= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRCS))
DEPS		= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.d, $(SRCS))

ifeq ($(MAKECMDGOALS), debug)
	CPPFLAGS		+= -D DEBUG=1
endif

all	: $(NAME)
debug : $(NAME)

$(NAME)	: $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -c $< $(INC) -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean	: clean
	rm -rf $(NAME)

re : clean
	make all

-include $(DEPS)

.PHONY : all clean fclean re
