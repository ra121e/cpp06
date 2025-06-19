# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/13 19:38:42 by athonda           #+#    #+#              #
#    Updated: 2025/06/19 18:01:21 by athonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Serializer

SRC_F	=	main.cpp \
			Serializer.cpp

SRC_DIR	=	.
SRC		=	$(SRC_F:%.cpp=$(SRC_DIR)/%.cpp)

OBJ_DIR	=	obj
OBJ		=	$(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC_F))

INC_DIR	=	.
DEP		=	$(wildcard $(patsubst %.cpp,$(INC_DIR)/%.hpp,$(SRC_F)))

CC		=	c++
CFLAGS	=	-g -Wall -Werror -Wextra -std=c++98
IFLAGS	=	-I$(INC_DIR)

$(NAME): $(OBJ) $(DEP)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEP)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: all debug clean flean re

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	clear
	nm -u $(NAME)
	grep -n -e "main" $(SRC) $(DEP)
