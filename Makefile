# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkling <mkling@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 14:56:12 by mkling            #+#    #+#              #
#    Updated: 2024/09/24 12:35:12 by mkling           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRC_DIR		= ./src

BIN_DIR		= ./bin

INC_DIR		= ./inc

SRCS		= $(wildcard $(SRC_DIR)/*.c)

LIBS		= ./inc/libft/libft.a

OBJS		= $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRCS))

CC			= cc

CFLAGS		= -Wall -Wextra -Werror


all:		${NAME}

${NAME}:	${OBJS}
			$(MAKE) -C ./inc/libft
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBS)

$(BIN_DIR)/%.o:		$(SRC_DIR)/%.c
					mkdir -p $(BIN_DIR)
					$(CC) $(CFLAGS) $(foreach dir,$(INC_DIR), -I$(dir)) -c $< -o $@

debug:		${OBJS}
			$(MAKE) -C ./inc/libft
			$(CC) $(CFLAGS) -g -o $(NAME) $(SRCS) $(LIBS)

clean:
			$(MAKE) -C ./inc/libft clean
			rm -rf $(BIN_DIR)

fclean:		clean
			rm -rf $(NAME)
			rm -rf ./inc/libft.a

re:			fclean all

.PHONY:		all clean fclean re debug
