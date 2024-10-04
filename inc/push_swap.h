/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:02:12 by mkling            #+#    #+#             */
/*   Updated: 2024/10/04 16:50:31 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

enum e_optimization
{
	NONE = 0,
	ROT_UP = 1,
	REV_DO = 2,
};

/* STACK HANDLING */
void	init_stacks(int argc, char **argv, t_dlst **stack_a, t_dlst **stack_b);
void	add_on_top_of_stack(t_dlst **stack, t_dlst *node);
void	add_on_bottom_of_stack(t_dlst **stack, t_dlst *node);
t_dlst	*find_bottom_node(t_dlst *lst);
t_dlst	*extract_top_node(t_dlst **src);
t_dlst	*extract_bottom_node(t_dlst **src);
int		stack_len(t_dlst *stack);

/* INDEXING */
t_dlst	*find_max(t_dlst *stack);
t_dlst	*find_min(t_dlst *stack);
void	set_index(t_dlst *stack, t_dlst *if_other_stack);
void	set_target_closest_bigger(t_dlst *stack_src, t_dlst *stack_dest);
void	set_target_closest_smaller(t_dlst *stack_src, t_dlst *stack_dest);
int		find_median_value(t_dlst *stack, int stack_len);

/* COMMANDS */
void	swap_top(t_dlst **stack, t_dlst **if_other_stack);
void	push_top(t_dlst **src, t_dlst **dest);
void	rotate_up(t_dlst **stack, t_dlst **if_other_stack);
void	rotate_down(t_dlst **stack, t_dlst **if_other_stack);

/* SORTING */
int		is_sorted(t_dlst *stack);
void	tiny_sort(t_dlst **stack_a);
void	tiny_sort_to_nearest_rotation(t_dlst **stack);
void	set_push_cost(t_dlst *src, t_dlst *dest);
void	push_cheapest(t_dlst **src, t_dlst **dest);
void	mecha_turk_sort(t_dlst **stack_a, t_dlst **stack_b);
void	rotate_to_top(t_dlst **stack, t_dlst *node);
void	push_big_to_top_small_to_bottom(t_dlst **a, t_dlst **b);

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
