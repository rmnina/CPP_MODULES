# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 15:33:28 by jdufour           #+#    #+#              #
#    Updated: 2024/05/12 21:31:27 by jdufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BSP

SRC_DIR = src

SRCS = $(addprefix $(SRC_DIR)/, main.cpp Fixed.cpp Point.cpp bsp.cpp)

OBJ_DIR = obj

OBJ = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rfv

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re