/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:55:42 by mkling            #+#    #+#             */
/*   Updated: 2024/10/08 14:42:23 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../lib/libft/inc/libft.h"

typedef struct s_doublelst
{
	int					data;
	int					index;
	int					push_cost;
	bool				in_top_half;
	bool				above_median;
	char				stack_id;
	struct s_doublelst	*next;
	struct s_doublelst	*prev;
	struct s_doublelst	*target;
}	t_dlst;

/* STACK HANDLING */
void	init_stacks(int argc, char **argv, t_dlst **stack_a, t_dlst **stack_b);
void	add_on_top_of_stack(t_dlst **stack, t_dlst *node);
void	add_on_bottom_of_stack(t_dlst **stack, t_dlst *node);
t_dlst	*find_bottom_node(t_dlst *lst);
t_dlst	*extract_top_node(t_dlst **src);
t_dlst	*extract_bottom_node(t_dlst **src);
int		stack_len(t_dlst *stack);
void	doublelst_clear(t_dlst **stack);

/* ERRORS */
int		is_overflow(long num);
int		is_duplicate(t_dlst *stack, int num);
int		contains_non_digit(char *str);
int		is_valid_command(char *str);
int		error_exit(t_dlst **stack, t_dlst **if_other_stack, char *line);

/* COMMANDS */
void	swap_top(t_dlst **a, t_dlst **b, char *cmd);
void	push_top(t_dlst **a, t_dlst **b, char *cmd);
void	rotate_up(t_dlst **a, t_dlst **b, char *cmd);
void	rotate_down(t_dlst **a, t_dlst **b, char *cmd);
void	parse_command(char *line, t_dlst **stack_a, t_dlst **stack_b);

/* SORTING */
int		is_sorted(t_dlst *stack);

/* DEBUG */
void	print_stack(t_dlst **stack);
void	print_both_stacks(t_dlst **a, t_dlst **b);
int		stack_len(t_dlst *stack);

#endif
