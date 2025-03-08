# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 19:01:05 by jdufour           #+#    #+#              #
#    Updated: 2025/03/08 21:35:43 by jdufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CHECKER_NAME = checker

SRC_DIR = src

SRCS = $(addprefix $(SRC_DIR)/, PMergeMe.cpp main.cpp)
CHECKER_SRC = $(addprefix $(SRC_DIR)/, checker.cpp)

OBJ_DIR = obj

OBJ = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
CHECKER_OBJ = $(CHECKER_SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

RM = rm -rfv

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $^ -o $@

$(CHECKER_NAME) : $(CHECKER_OBJ)
	$(CXX) $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ) $(CHECKER_OBJ)

fclean : clean
	$(RM) $(NAME) $(CHECKER_NAME)

re : fclean all

.PHONY : all clean fclean re checker