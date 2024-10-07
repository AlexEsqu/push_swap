/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targeting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:36:43 by mkling            #+#    #+#             */
/*   Updated: 2024/10/07 16:46:07 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	if (stack_len % 2 == 0)
		median = num_tab[stack_len / 2];
	else
		median = (num_tab[stack_len / 2] + num_tab[(stack_len + 1) / 2]) / 2;
	free(num_tab);
	return (median);
}

void	set_if_above_median(t_dlst *a)
{
	int	median;

	median = find_median_value(a, stack_len(a));
	while (a)
	{
		a->above_median = (a->data > median);
		a = a->next;
	}
}

void	set_target_closest_smaller(t_dlst *node, t_dlst *dest)
{
	t_dlst	*target;

	while (node)
	{
		node->target = NULL;
		target = dest;
		while (target)
		{
			if ((target->data < node->data) && (node->target == NULL
					|| target->data > node->target->data))
				node->target = target;
			target = target->next;
		}
		if (node->target == NULL)
			node->target = find_max(dest);
		node = node->next;
	}
}

void	set_target_closest_bigger(t_dlst *node, t_dlst *dest)
{
	t_dlst	*target;

	while (node)
	{
		node->target = NULL;
		target = dest;
		while (target)
		{
			if ((target->data > node->data) && (node->target == NULL
					|| target->data < node->target->data))
				node->target = target;
			target = target->next;
		}
		if (node->target == NULL)
			node->target = find_min(dest);
		node = node->next;
	}
}
