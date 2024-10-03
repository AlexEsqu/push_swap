/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:11:15 by mkling            #+#    #+#             */
/*   Updated: 2024/10/02 11:29:40 by mkling           ###   ########.fr       */
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
		top_node->stack_id = 'a';
		write(1, "pa\n", 3);
	}
	else
	{
		top_node->stack_id = 'b';
		write(1, "pb\n", 3);
	}
	set_index(*src, *dest);
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
		write(1, "r", 1);
		write(1, &(*stack)->stack_id, 1);
		write(1, "\n", 1);
		set_index(*stack, NULL);
		return ;
	}
	if (!*if_other_stack || !(*if_other_stack)->next)
		return ;
	top = extract_top_node(if_other_stack);
	add_on_bottom_of_stack(if_other_stack, top);
	set_index(*stack, *if_other_stack);
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
		write(1, "rr", 2);
		write(1, &(*stack)->stack_id, 1);
		write(1, "\n", 1);
		set_index(*stack, NULL);
		return ;
	}
	if (!*if_other_stack || !(*if_other_stack)->next)
		return ;
	bottom = extract_bottom_node(if_other_stack);
	add_on_top_of_stack(if_other_stack, bottom);
	set_index(*stack, *if_other_stack);
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
		write(1, "s", 1);
		write(1, &(*stack)->stack_id, 1);
		write(1, "\n", 1);
		set_index(*stack, NULL);
		return ;
	}
	tmp = (*if_other_stack)->data;
	(*if_other_stack)->data = (*if_other_stack)->next->data;
	(*if_other_stack)->next->data = tmp;
	set_index(*stack, *if_other_stack);
	write(1, "ss\n", 3);
}
