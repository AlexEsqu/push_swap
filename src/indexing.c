/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:49:47 by mkling            #+#    #+#             */
/*   Updated: 2024/10/04 12:30:32 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*find_max(t_dlst *stack)
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

t_dlst	*find_min(t_dlst *stack)
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

int	find_median_value(t_dlst *stack, int stack_len)
{
	int		median;
	int		*num_tab;
	t_dlst	*current;

	num_tab = ft_calloc((stack_len), sizeof(int));
	current = stack;
	while (current)
	{
		num_tab[current->index] = current->data;
		current = current->next;
	}
	ft_bubble_sort(num_tab, stack_len);
	median = num_tab[(stack_len + 1) / 2 -1];
	free(num_tab);
	return (median);
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
	int	middle;
	int	median;
	int	len_stack;

	index = 0;
	len_stack = stack_len(stack);
	middle = len_stack / 2;
	median = find_median_value(stack, len_stack);
	while (stack)
	{
		stack->index = index;
		stack->in_top_half = (index < middle);
		stack->above_median = (stack->data > median);
		index++;
		stack = stack->next;
	}
	if (if_other_stack)
		set_index(if_other_stack, NULL);
}
