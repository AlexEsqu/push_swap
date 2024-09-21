/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:57:19 by mkling            #+#    #+#             */
/*   Updated: 2024/09/21 15:17:31 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_push_cost(t_dlst *stack_src, t_dlst *stack_dest)
{
	int	len_src;
	int	len_dest;

	len_src = stack_len(stack_src);
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

t_dlst	*get_cheapest_move(t_dlst *stack_src)
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

void	push_cheapest(t_dlst **stack_src, t_dlst **stack_dest)
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
