/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:49:47 by mkling            #+#    #+#             */
/*   Updated: 2024/09/23 16:39:33 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_dlst **stack)
{
	if (is_sorted(*stack))
		return ;
	if (stack_len(*stack) > 2)
	{
		if ((*stack)->next->data > (*stack)->next->next->data)
		{
			swap_top(stack, NULL);
			rotate_up(stack, NULL);
		}
		if ((*stack)->data > (*stack)->next->next->data)
			rotate_up(stack, NULL);
	}
	if ((*stack)->data > (*stack)->next->data)
		swap_top(stack, NULL);
}

void	rotate_to_top(t_dlst **stack, t_dlst *node)
{
	set_index(*stack);
	while ((*stack)->data != node->data)
	{
		if (node->is_above_median)
			rotate_up(stack, NULL);
		else
			rotate_down(stack, NULL);
	}
}

void	mecha_turk_sort(t_dlst **stack_a, t_dlst **stack_b)
{
	while (stack_len(*stack_a) > 3 && stack_len(*stack_b) < 2)
		push_top(stack_a, stack_b);
	while (stack_len(*stack_a) > 3)
	{
		set_index(*stack_a);
		set_index(*stack_b);
		set_target_closest_smaller(*stack_a, *stack_b);
		set_push_cost(*stack_a, *stack_b);
		push_cheapest(stack_a, stack_b);
	}
	tiny_sort(stack_a);
	while (stack_len(*stack_b) > 0)
	{
		set_index(*stack_a);
		set_index(*stack_b);
		set_target_closest_bigger(*stack_b, *stack_a);
		set_push_cost(*stack_b, *stack_a);
		push_cheapest(stack_b, stack_a);
	}
	rotate_to_top(stack_a, find_smallest_num_in_stack(*stack_a));
}
