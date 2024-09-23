/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:02:12 by mkling            #+#    #+#             */
/*   Updated: 2024/09/23 16:42:30 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../inc/libft/libft.h"

typedef struct s_doublelst
{
	int					data;
	int					index;
	int					push_cost;
	bool				is_above_median;
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
void	success_exit(t_dlst *stack_a);

/* INDEXING */
t_dlst	*find_biggest_num_in_stack(t_dlst *stack);
t_dlst	*find_smallest_num_in_stack(t_dlst *stack);
void	set_index(t_dlst *stack);
void	set_target_closest_bigger(t_dlst *stack_src, t_dlst *stack_dest);
void	set_target_closest_smaller(t_dlst *stack_src, t_dlst *stack_dest);
void	set_push_cost(t_dlst *stack_src, t_dlst *stack_dest);
t_dlst	*get_cheapest_move(t_dlst *stack_src);

/* COMMANDS */
void	swap_top(t_dlst **stack, t_dlst **if_other_stack);
void	push_top(t_dlst **src, t_dlst **dest);
void	rotate_up(t_dlst **stack, t_dlst **if_other_stack);
void	rotate_down(t_dlst **stack, t_dlst **if_other_stack);

/* SORTING */
int		is_sorted(t_dlst *stack);
void	tiny_sort(t_dlst **stack_a);
void	mecha_turk_sort(t_dlst **stack_a, t_dlst **stack_b);
void	rotate_to_top(t_dlst **stack, t_dlst *node);
void	push_cheapest(t_dlst **stack_src, t_dlst **stack_dest);

/* ERRORS */
int		is_overflow(long num);
int		is_duplicate(t_dlst *stack, int num);
int		contains_non_digit(char *str);
int		error_exit(t_dlst *stack);
void	doublelst_clear(t_dlst *stack);

/* DEBUG */
void	print_stack(t_dlst **stack);
void	print_both_stacks(t_dlst **a, t_dlst **b);

#endif
