/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targeting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:36:43 by mkling            #+#    #+#             */
/*   Updated: 2024/10/07 02:45:19 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
