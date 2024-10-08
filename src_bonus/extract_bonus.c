/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:17:03 by mkling            #+#    #+#             */
/*   Updated: 2024/10/08 14:52:06 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

t_dlst	*find_bottom_node(t_dlst *lst)
{
	t_dlst	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

t_dlst	*extract_top_node(t_dlst **src)
{
	t_dlst	*top_node;

	top_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	top_node->prev = NULL;
	top_node->next = NULL;
	return (top_node);
}

t_dlst	*extract_bottom_node(t_dlst **src)
{
	t_dlst	*bottom_node;

	if (stack_len(*src) == 1)
	{
		bottom_node = (*src);
		*src = NULL;
	}
	else
	{
		bottom_node = find_bottom_node(*src);
		bottom_node->prev->next = NULL;
	}
	bottom_node->prev = NULL;
	bottom_node->next = NULL;
	return (bottom_node);
}

void	add_on_top_of_stack(t_dlst **stack, t_dlst *node)
{
	if (*stack == NULL)
	{
		*stack = node;
		node->next = NULL;
	}
	else
	{
		node->next = *stack;
		node->next->prev = node;
		*stack = node;
	}
}

void	add_on_bottom_of_stack(t_dlst **stack, t_dlst *node)
{
	t_dlst	*last_node;

	last_node = *stack;
	if (node == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	else
	{
		last_node = find_bottom_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
