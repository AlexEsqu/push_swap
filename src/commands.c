/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:11:15 by mkling            #+#    #+#             */
/*   Updated: 2024/09/23 16:41:59 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_dlst **src, t_dlst **dest)
{
	t_dlst	*top_node;

	if (*src == NULL)
		return ;
	top_node = extract_top_node(src);
	add_on_top_of_stack(dest, top_node);
	if (top_node->stack_id == 'b')
	{
		write(1, "pa\n", 3);
		top_node->stack_id = 'a';
	}
	else
	{
		top_node->stack_id = 'b';
		write(1, "pb\n", 3);
	}
}

void	rotate_up(t_dlst **stack, t_dlst **if_other_stack)
{
	t_dlst	*top;

	if (!(*stack) || !(*stack)->next)
		return ;
	top = extract_top_node(stack);
	add_on_bottom_of_stack(stack, top);
	if (if_other_stack == NULL)
	{
		if ((*stack)->stack_id == 'a')
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
		return ;
	}
	if (!*if_other_stack || !(*if_other_stack)->next)
		return ;
	top = extract_top_node(if_other_stack);
	add_on_bottom_of_stack(if_other_stack, top);
	write(1, "rr\n", 3);
}

void	rotate_down(t_dlst **stack, t_dlst **if_other_stack)
{
	t_dlst	*bottom;

	if (!*stack || !(*stack)->next)
		return ;
	bottom = extract_bottom_node(stack);
	add_on_top_of_stack(stack, bottom);
	if (if_other_stack == NULL)
	{
		if (bottom->stack_id == 'a')
			write(1, "rra\n", 4);
		else if (bottom->stack_id == 'b')
			write(1, "rrb\n", 4);
		return ;
	}
	if (!*if_other_stack || !(*if_other_stack)->next)
		return ;
	bottom = extract_bottom_node(if_other_stack);
	add_on_top_of_stack(if_other_stack, bottom);
	write(1, "rrr\n", 4);
}

void	swap_top(t_dlst **stack, t_dlst **if_other_stack)
{
	int	tmp;

	if (!(*stack) | !(*stack)->next)
		return ;
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
	if (if_other_stack == NULL)
	{
		if ((*stack)->stack_id == 'a')
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
		return ;
	}
	tmp = (*if_other_stack)->data;
	(*if_other_stack)->data = (*if_other_stack)->next->data;
	(*if_other_stack)->next->data = tmp;
	write(1, "ss\n", 3);
}
