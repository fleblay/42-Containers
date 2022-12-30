SHELL		= /bin/bash

NAME		= containers
CPPFLAGS	= -MMD -Wall -Wextra -Werror -std=c++98
#-MMD : first M for dependencies, second M to ignore system header directories, D to output to file .d with same name as .o file
CPP			= c++

SRC_DIR		= ./src
HEADER_DIR	= ./inc
OBJ_DIR		= ./obj
INC			= -I $(HEADER_DIR)

ifndef TEST_FILE
	SRC_LIST	:= main.cpp
else
	SRC_LIST	:= ${TEST_FILE}
endif

HEADER_LIST	= containers.hpp iterator.hpp random_access_iterator.hpp random_access_iterator.tpp vector.hpp vector.tpp

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_LIST))
HEADERS		= $(addprefix $(HEADER_DIR)/, $(HEADER_LIST))
OBJS		= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRCS))
DEPS		= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.d, $(SRCS))

ifeq ($(MAKECMDGOALS), debug)
	CPPFLAGS	+= -D DEBUG=1
else
	CPPFLAGS	+= -D DEBUG=0
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
