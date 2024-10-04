/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:49:47 by mkling            #+#    #+#             */
/*   Updated: 2024/10/04 19:33:48 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	int		index;
	int		*num_tab;
	t_dlst	*current;

	num_tab = (int *)ft_calloc((stack_len + 1), sizeof(int));
	current = stack;
	index = 0;
	while (current)
	{
		num_tab[index] = current->data;
		index++;
		current = current->next;
	}
	ft_bubble_sort(num_tab, stack_len);
	fprintf(stderr, "is sorted\n");
	if (stack_len % 2 == 0)
		median = num_tab[stack_len / 2];
	else
		median = (num_tab[stack_len / 2] + num_tab[(stack_len + 1) / 2]) / 2;
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
	int	len_stack;

	index = 0;
	len_stack = stack_len(stack);
	middle = len_stack / 2;
	while (stack)
	{
		stack->index = index;
		stack->in_top_half = (index < middle);
		index++;
		stack = stack->next;
	}
	if (if_other_stack)
		set_index(if_other_stack, NULL);
}
