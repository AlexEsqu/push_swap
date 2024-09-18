/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:50:53 by mkling            #+#    #+#             */
/*   Updated: 2024/09/18 13:59:14 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_overflow(int num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

int	is_duplicate(t_dlst **stack, int num)
{
	t_dlst	*itering;

	itering = NULL;
	if (*stack == 0)
		return (0);
	while (itering)
	{
		if (itering->data == num)
			return (1);
		itering = itering->next;
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
