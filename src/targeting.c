/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targeting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:36:43 by mkling            #+#    #+#             */
/*   Updated: 2024/10/04 11:49:43 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
