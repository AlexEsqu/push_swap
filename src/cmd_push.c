/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:28:18 by mkling            #+#    #+#             */
/*   Updated: 2024/09/18 17:20:50 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_dlst **src, t_dlst **dest)
{
	t_dlst	*top_node;

	if (*src == NULL)
		return ;
	top_node = extract_top_node(src);
	add_on_top_of_stack(dest, top_node);
}

void	push_pa(t_dlst **stack_b, t_dlst **stack_a)
{
	push_top(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_pb(t_dlst **stack_a, t_dlst **stack_b)
{
	push_top(stack_a, stack_b);
	write(1, "pb\n", 3);
}
