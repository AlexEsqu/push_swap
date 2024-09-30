/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targeting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:36:43 by mkling            #+#    #+#             */
/*   Updated: 2024/09/30 15:34:25 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_closest_smallest(t_dlst *node, t_dlst *stack)
{
	t_dlst	*current;

	current = stack;
	while (current)
	{
		if ((current->data < node->data) && (node->target == NULL
				|| current->data > node->target->data))
			node->target = current;
		current = current->next;
	}
}

void	find_closest_bigger(t_dlst *node, t_dlst *stack)
{
	t_dlst	*current;

	current = stack;
	while (current)
	{
		if ((current->data > node->data) && (node->target == NULL
				|| current->data < node->target->data))
			node->target = current;
		current = current->next;
	}
}

void	set_target_closest_smaller(t_dlst *stack_src, t_dlst *stack_dest)
{
	while (stack_src)
	{
		stack_src->target = NULL;
		find_closest_smallest(stack_src, stack_dest);
		if (stack_src->target == NULL)
			stack_src->target = find_biggest_num_in_stack(stack_dest);
		stack_src = stack_src->next;
	}
}

void	set_target_closest_bigger(t_dlst *stack_src, t_dlst *stack_dest)
{
	while (stack_src)
	{
		stack_src->target = NULL;
		find_closest_bigger(stack_src, stack_dest);
		if (stack_src->target == NULL)
			stack_src->target = find_smallest_num_in_stack(stack_dest);
		stack_src = stack_src->next;
	}
}
