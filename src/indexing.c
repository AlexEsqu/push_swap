/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:49:47 by mkling            #+#    #+#             */
/*   Updated: 2024/09/23 17:03:20 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*find_biggest_num_in_stack(t_dlst *stack)
{
	t_dlst	*biggest;

	biggest = stack;
	while (stack)
	{
		if (stack->data > biggest->data)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

t_dlst	*find_smallest_num_in_stack(t_dlst *stack)
{
	t_dlst	*smallest;

	smallest = stack;
	while (stack)
	{
		if (stack->data < smallest->data)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

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

int	stack_len(t_dlst *stack)
{
	int	stack_len;

	stack_len = 0;
	while (stack != NULL)
	{
		stack_len++;
		stack = stack->next;
	}
	return (stack_len);
}

void	set_index(t_dlst *stack, t_dlst *if_other_stack)
{
	int	index;
	int	median;

	index = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = index;
		stack->is_above_median = (index < median);
		index++;
		stack = stack->next;
	}
	if (if_other_stack)
		set_index(if_other_stack, NULL);
}
