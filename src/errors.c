/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:50:53 by mkling            #+#    #+#             */
/*   Updated: 2024/09/19 14:31:50 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_overflow(int num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

int	is_duplicate(t_dlst *stack, int num)
{
	if (stack == 0)
		return (0);
	while (stack)
	{
		if (stack->data == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	doublelst_clear(t_dlst *stack)
{
	t_dlst	*next_node;
	t_dlst	*current_node;

	current_node = stack;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	stack = NULL;
}

int	error_exit(t_dlst *stack)
{
	if (stack)
		doublelst_clear(stack);
	write(1, "Error\n", 6);
	exit(1);
}

void	success_exit(t_dlst *stack_a, t_dlst *stack_b)
{
	doublelst_clear(stack_a);
	doublelst_clear(stack_b);
	exit(0);
}
