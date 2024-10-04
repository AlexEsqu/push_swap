/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:07:30 by mkling            #+#    #+#             */
/*   Updated: 2024/10/04 12:46:42 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_dlst *stack)
{
	if (!stack)
		return (true);
	while (stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	push_big_to_top_small_to_bottom(t_dlst **a, t_dlst **b)
{
	if ((*a)->above_median)
		push_top(a, b);
	else
	{
		push_top(a, b);
		rotate_up(b, NULL);
	}
}

void	tiny_sort_to_nearest_rotation(t_dlst **stack)
{
	t_dlst	*max;
	t_dlst	*min;
	t_dlst	*top;
	t_dlst	*middle;
	t_dlst	*bottom;

	max = find_max(*stack);
	min = find_min(*stack);
	top = (*stack);
	middle = (*stack)->next;
	bottom = (*stack)->next->next;
	if ((bottom == max && middle == min)
		|| (top == max && bottom == min)
		|| (middle == max && top == min))
		swap_top(stack, NULL);
}

void	tiny_sort(t_dlst **stack)
{
	tiny_sort_to_nearest_rotation(stack);
	rotate_to_top(stack, find_min(*stack));
}
