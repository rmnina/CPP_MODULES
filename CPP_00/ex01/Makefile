# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 16:52:34 by jdufour           #+#    #+#              #
#    Updated: 2024/04/25 23:15:18 by jdufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRC_DIR = src

SRCS = $(addprefix $(SRC_DIR)/, phonebook.cpp contact.cpp main.cpp)

OBJ_DIR = obj

OBJ = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rfv

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re