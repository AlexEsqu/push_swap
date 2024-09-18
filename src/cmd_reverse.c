/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:06:15 by mkling            #+#    #+#             */
/*   Updated: 2024/09/18 17:22:26 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_down(t_dlst **stack)
{
	t_dlst	*bottom_node;

	if (*stack == NULL)
		return ;
	bottom_node = extract_bottom_node(stack);
	add_on_top_of_stack(stack, bottom_node);
}

void	rrev_rra(t_dlst **stack_a)
{
	rotate_down(stack_a);
	write(1, "rra\n", 4);
}

void	rrev_rrb(t_dlst **stack_b)
{
	rotate_down(stack_b);
	write(1, "rrb\n", 4);
}

void	rrev_rrr(t_dlst **stack_a, t_dlst **stack_b)
{
	rotate_down(stack_a);
	rotate_down(stack_b);
	write(1, "rrr\n", 4);
}
