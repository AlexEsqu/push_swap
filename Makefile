# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkling <mkling@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 14:56:12 by mkling            #+#    #+#              #
#    Updated: 2024/10/07 02:44:18 by mkling           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
NAME		= push_swap

NAME_BONUS	= checker


# Directory
SRC_DIR		= src

OBJ_DIR		= obj

INC_DIR		= inc

LIB_DIR		= lib

SRCB_DIR	= src_bonus

OBJB_DIR	= obj_bonus

# Files
SRCS		= commands.c \
			errors.c \
			extract_append.c \
			indexing.c \
			main.c \
			sorting.c \
			stack.c \
			targeting.c \
			tiny_sort.c \

SRCS_BON	= commands_bonus.c \
			errors_bonus.c \
			extract_bonus.c \
			main_bonus.c \
			stack_bonus.c \

LIBS		= ./lib/libft/libft.a

OBJS		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(addprefix $(SRC_DIR)/, $(SRCS)))

OBJS_BON	= $(patsubst $(SRCB_DIR)/%.c,$(OBJB_DIR)/%.o,$(addprefix $(SRCB_DIR)/, $(SRCS_BON)))


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

bonus: 		$(OBJS_BON)
			$(MAKE) -C ./lib/libft
			$(CC) $(CFLAGS) -I$(INC_DIR) $(OBJS_BON) $(LIBS) -o $(NAME_BONUS)

$(OBJB_DIR)/%.o:	$(SRCB_DIR)/%.c
					mkdir -p $(OBJB_DIR)
					$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

debug:		$(OBJS)
			$(MAKE) -C ./lib/libft
			$(CC) $(CFLAGS) -g -I$(INC_DIR) $(OBJS) $(LIBS) -o $(NAME)

clean:
			$(MAKE) -C ./lib/libft clean
			rm -rf $(OBJ_DIR)

fclean:
			$(MAKE) -C ./lib/libft fclean
			rm -rf $(OBJ_DIR)
			rm -rf $(OBJB_DIR)
			rm -rf $(NAME)
			rm -rf $(NAME_BONUS)

re:			fclean all

.PHONY:		all clean fclean re debug
