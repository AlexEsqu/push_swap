/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:49:47 by mkling            #+#    #+#             */
/*   Updated: 2024/09/21 11:57:39 by mkling           ###   ########.fr       */
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

void	set_index(t_dlst *stack)
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
}
