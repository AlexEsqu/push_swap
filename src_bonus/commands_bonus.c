/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:11:15 by mkling            #+#    #+#             */
/*   Updated: 2024/10/07 02:51:00 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	push_top(t_dlst **a, t_dlst **b, char *cmd)
{
	t_dlst	*top_node;

	if (*a == NULL || *b == NULL)
		error_exit((*a), (*b));
	if (cmd[1] == 'a')
	{
		top_node = extract_top_node(a);
		add_on_top_of_stack(b, top_node);
		top_node->stack_id = 'b';
	}
	if (cmd[1] == 'b')
	{
		top_node = extract_top_node(b);
		add_on_top_of_stack(a, top_node);
		top_node->stack_id = 'a';
	}
}

void	rotate_up(t_dlst **a, t_dlst **b, char *cmd)
{
	t_dlst	*top;

	if (cmd[1] == 'a')
	{
		if (!(*a) || !(*a)->next)
			error_exit((*a), (*b));
		top = extract_top_node(a);
		add_on_bottom_of_stack(a, top);
	}
	if (cmd[1] == 'b')
	{
		if (!(*b) || !(*b)->next)
			error_exit((*a), (*b));
		top = extract_top_node(b);
		add_on_bottom_of_stack(b, top);
	}
	if (cmd[1] == 'r' && (cmd[2] == '\n'))
	{
		if (!(*a) || !(*a)->next || !(*b) || !(*b)->next)
			error_exit((*a), (*b));
		top = extract_top_node(a);
		add_on_bottom_of_stack(a, top);
		top = extract_top_node(b);
		add_on_bottom_of_stack(b, top);
	}
}

void	rotate_down(t_dlst **a, t_dlst **b, char *cmd)
{
	t_dlst	*bottom;

	if (cmd[2] == 'a')
	{
		if (!(*a) || !(*a)->next)
			error_exit((*a), (*b));
		bottom = extract_bottom_node(a);
		add_on_top_of_stack(a, bottom);
	}
	if (cmd[2] == 'b')
	{
		if (!(*b) || !(*b)->next)
			error_exit((*a), (*b));
		bottom = extract_bottom_node(b);
		add_on_top_of_stack(b, bottom);
	}
	if (cmd[2] == 'r')
	{
		if (!(*a) || !(*a)->next || !(*b) || !(*b)->next)
			error_exit((*a), (*b));
		bottom = extract_bottom_node(a);
		add_on_top_of_stack(a, bottom);
		bottom = extract_bottom_node(b);
		add_on_top_of_stack(b, bottom);
	}
}

void	swap_top(t_dlst **a, t_dlst **b, char *cmd)
{
	if (cmd[1] == 'a')
	{
		if (!(*a) || !(*a)->next)
			error_exit((*a), (*b));
		ft_swap_int(&(*a)->data, &(*a)->next->data);
	}
	if (cmd[1] == 'b')
	{
		if (!(*b) || !(*b)->next)
			error_exit((*a), (*b));
		ft_swap_int(&(*b)->data, &(*b)->next->data);
	}
	if (cmd[1] == 's')
	{
		if (!(*a) || !(*a)->next || !(*b) || !(*b)->next)
			error_exit((*a), (*b));
		ft_swap_int(&(*a)->data, &(*a)->next->data);
		ft_swap_int(&(*b)->data, &(*b)->next->data);
	}
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
