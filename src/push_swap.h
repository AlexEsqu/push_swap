/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:02:12 by mkling            #+#    #+#             */
/*   Updated: 2024/09/18 17:22:35 by mkling           ###   ########.fr       */
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

typedef struct s_doublelst {
	int					data;
	struct s_doublelst	*next;
	struct s_doublelst	*prev;
}	t_dlst;

/* STACK HANDLING */
t_dlst	*init_stack(int argc, char **argv);
t_dlst	*find_last_node(t_dlst *lst);
void	add_on_top_of_stack(t_dlst **stack, t_dlst *node);
void	add_on_bottom_of_stack(t_dlst **stack, t_dlst *node);
t_dlst	*extract_top_node(t_dlst **src);
t_dlst	*extract_bottom_node(t_dlst **src);

/* COMMANDS */
void	swap_sa(t_dlst **stack_a);
void	swap_sb(t_dlst **stack_b);
void	swap_ss(t_dlst **stack_a, t_dlst **stack_b);
void	push_pa(t_dlst **stack_b, t_dlst **stack_a);
void	push_pb(t_dlst **stack_a, t_dlst **stack_b);
void	rota_ra(t_dlst **stack_a);
void	rota_rb(t_dlst **stack_b);
void	rota_rr(t_dlst **stack_a, t_dlst **stack_b);
void	rrev_rra(t_dlst **stack_a);
void	rrev_rrb(t_dlst **stack_b);
void	rrev_rrr(t_dlst **stack_a, t_dlst **stack_b);

/* SORTING */


/* ERRORS */
int		is_overflow(int num);
int		is_duplicate(t_dlst **stack, int num);
int		error_exit(t_dlst *stack);

#endif
