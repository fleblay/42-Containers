SHELL		= /bin/bash

NAME		= containers
CPPFLAGS	= -MMD -Wall -Wextra -Werror -g3 #-fsanitize=address
#-MMD : first M for dependencies, second M to ignore system header directories, D to output to file .d with same name as .o file
CPP			= c++

SRC_DIR		= ./src
HEADER_DIR	= ./inc
OBJ_DIR		= ./obj
INC			= -I $(HEADER_DIR) -I ./containers_test/srcs/set

ifndef IGNORE_STD_98
	CPPFLAGS	+= -std=c++98
endif

ifndef TEST_FILE
	SRC_LIST	:= main.cpp
else
	SRC_LIST	:= ${TEST_FILE}
endif

HEADER_LIST	= const_node_iterator.hpp containers.hpp distance.hpp enable_if.hpp equal.hpp is_integral.hpp iterator.hpp lexicographical_compare.hpp map.hpp\
node_iterator.hpp pair.hpp random_access_iterator.hpp rbtree.hpp reverse_iterator.hpp\
stack.hpp vector.hpp set.hpp

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_LIST))
HEADERS		= $(addprefix $(HEADER_DIR)/, $(HEADER_LIST))
OBJS		= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRCS))
DEPS		= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.d, $(SRCS))

ifeq ($(MAKECMDGOALS), debug)
	CPPFLAGS	+= -D DEBUG=1
endif

ifeq ($(MAKECMDGOALS), std)
	CPPFLAGS	+= -D NAMESPACE=std
	NAME		= stdcontainers
	OBJ_DIR		= ./std_obj
endif

all	: $(NAME)
std	: $(NAME)
debug : fclean $(NAME)

$(NAME)	: $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -c $< $(INC) -o $@

clean :
	rm -rf $(OBJ_DIR)
	rm -rf ./std_obj

fclean	: clean
	rm -rf $(NAME)
	rm -rf stdcontainers
	./unit_test.sh "clean"

re : clean
	make all

-include $(DEPS)

.PHONY : all clean fclean re
