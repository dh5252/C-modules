# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 14:40:23 by cahn              #+#    #+#              #
#    Updated: 2023/11/11 15:13:25 by cahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex02

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re