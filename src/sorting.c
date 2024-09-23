/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:49:47 by mkling            #+#    #+#             */
/*   Updated: 2024/09/23 17:04:11 by alex             ###   ########.fr       */
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

static void	set_push_cost(t_dlst *stack_src, t_dlst *stack_dest)
{
	int	len_dest;

	len_dest = stack_len(stack_dest);
	while (stack_src)
	{
		stack_src->push_cost = stack_src->index;
		if (stack_src->target->is_above_median)
			stack_src->push_cost += stack_src->target->index;
		else
			stack_src->push_cost += len_dest - stack_src->target->index;
		stack_src = stack_src->next;
	}
}

static t_dlst	*get_cheapest_move(t_dlst *stack_src)
{
	t_dlst	*cheapest;

	cheapest = stack_src;
	while (stack_src)
	{
		if (stack_src->push_cost == 0)
			return (stack_src);
		if (stack_src->push_cost < cheapest->push_cost)
			cheapest = stack_src;
		stack_src = stack_src->next;
	}
	return (cheapest);
}

static void	push_cheapest(t_dlst **stack_src, t_dlst **stack_dest)
{
	t_dlst	*cheapest;

	cheapest = get_cheapest_move(*stack_src);
	while ((*stack_src)->data != cheapest->data)
	{
		if (!cheapest->is_above_median && !cheapest->target->is_above_median)
			rotate_down(stack_src, stack_dest);
		else if (cheapest->is_above_median && cheapest->target->is_above_median)
			rotate_up(stack_src, stack_dest);
		else
			break ;
	}
	rotate_to_top(stack_src, cheapest);
	rotate_to_top(stack_dest, cheapest->target);
	push_top(stack_src, stack_dest);
}

void	mecha_turk_sort(t_dlst **stack_a, t_dlst **stack_b)
{
	while (stack_len(*stack_a) > 3 && stack_len(*stack_b) < 2)
		push_top(stack_a, stack_b);
	while (stack_len(*stack_a) > 3)
	{
		set_index(*stack_a, *stack_b);
		set_target_closest_smaller(*stack_a, *stack_b);
		set_push_cost(*stack_a, *stack_b);
		push_cheapest(stack_a, stack_b);
	}
	tiny_sort(stack_a);
	while (stack_len(*stack_b) > 0)
	{
		set_index(*stack_a, *stack_b);
		set_target_closest_bigger(*stack_b, *stack_a);
		set_push_cost(*stack_b, *stack_a);
		push_cheapest(stack_b, stack_a);
	}
	rotate_to_top(stack_a, find_smallest_num_in_stack(*stack_a));
}

