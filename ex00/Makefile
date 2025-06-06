# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 14:24:38 by athonda           #+#    #+#              #
#    Updated: 2025/06/06 09:20:52 by athonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Converter

SRC_F	=	main.cpp \
			Converter.cpp
SRC_DIR	=	.
SRC		=	$(SRC_DIR)/$(SRC_F)

OBJ_DIR	=	obj
OBJ		=	$(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC_F))

INC_DIR	=	.
DEP		=	$(wildcard $(patsubst %.cpp,$(INC_DIR)/%.hpp,$(SRC_F)))

CC		=	c++
CFLAGS	=	-g -Wall -Wextra -Werror -std=++98

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp, $(INC_DIR)/$(DEP)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(SRC) -c $< -o $@

.PHONY all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm $(NAME)

re: fclean
	all