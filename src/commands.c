/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:11:15 by mkling            #+#    #+#             */
/*   Updated: 2024/09/21 19:02:19 by mkling           ###   ########.fr       */
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
	if (top_node->e_stack == STACK_B)
	{
		write(1, "pa\n", 3);
		top_node->e_stack = STACK_A;
	}
	else
	{
		top_node->e_stack = STACK_B;
		write(1, "pb\n", 3);
	}
}

void	rotate_up(t_dlst **stack, t_dlst **if_other_stack)
{
	t_dlst	*top_node;

	if (*stack == NULL)
		return ;
	top_node = extract_top_node(stack);
	add_on_bottom_of_stack(stack, top_node);
	if (if_other_stack == NULL)
	{
		if ((*stack)->e_stack == STACK_A)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
		return ;
	}
	else
	top_node = extract_top_node(if_other_stack);
	add_on_bottom_of_stack(if_other_stack, top_node);
	write(1, "rr\n", 3);
}

void	rotate_down(t_dlst **stack, t_dlst **if_other_stack)
{
	t_dlst	*bottom_node;

	if (*stack == NULL || stack_len(*stack) == 1)
		return ;
	bottom_node = extract_bottom_node(stack);
	add_on_top_of_stack(stack, bottom_node);
	if (if_other_stack == NULL)
	{
		if (bottom_node->e_stack == STACK_A)
			write(1, "rra\n", 4);
		else if (bottom_node->e_stack == STACK_B)
			write(1, "rrb\n", 4);
		return ;
	}
	if (*if_other_stack == NULL || stack_len(*if_other_stack) == 1)
		return ;
	bottom_node = extract_bottom_node(if_other_stack);
	add_on_bottom_of_stack(if_other_stack, bottom_node);
	write(1, "rrr\n", 4);
}

void	ft_swap(int *num1, int *num2)
{
	int	tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void	swap_top(t_dlst **stack, t_dlst **if_other_stack)
{
	if ((*stack) == NULL | (*stack)->next == NULL)
		return ;
	ft_swap(&(*stack)->data, &(*stack)->next->data);
	if (if_other_stack == NULL)
	{
		if ((*stack)->e_stack == STACK_A)
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
		return ;
	}
	ft_swap(&(*if_other_stack)->data, &(*if_other_stack)->next->data);
	write(1, "ss\n", 3);
}


