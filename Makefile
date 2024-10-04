# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkling <mkling@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 14:56:12 by mkling            #+#    #+#              #
#    Updated: 2024/10/04 17:11:13 by mkling           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
NAME		= push_swap


# Directory
SRC_DIR		= src

OBJ_DIR		= obj

INC_DIR		= inc

LIB_DIR		= lib


# Files
SRCS		= commands.c \
			errors.c \
			extract_append.c \
			indexing.c \
			main.c \
			sorting.c \
			stack_handling.c \
			targeting.c \
			tiny_sort.c \

LIBS		= ./lib/libft/libft.a

OBJS		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(addprefix $(SRC_DIR)/, $(SRCS)))


# Compiler
CC			= cc

CFLAGS		= -Wall -Wextra -Werror


# General Rules
all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C ./lib/libft
			$(CC) $(CFLAGS) -I$(INC_DIR) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

debug:		$(OBJS)
			$(MAKE) -C ./lib/libft
			$(CC) -Wunitialized $(CFLAGS) -g -I$(INC_DIR) $(OBJS) $(LIBS) -o $(NAME)

clean:
			$(MAKE) -C ./lib/libft clean
			rm -rf $(OBJ_DIR)

fclean:
			$(MAKE) -C ./lib/libft fclean
			rm -rf $(OBJ_DIR)
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re debug
