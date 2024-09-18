/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:11:15 by mkling            #+#    #+#             */
/*   Updated: 2024/09/18 17:16:17 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(t_dlst **stack)
{
	t_dlst	*top_node;

	if (*stack == NULL)
		return ;
	top_node = extract_top_node(stack);
	add_on_bottom_of_stack(stack, top_node);
}

void	rota_ra(t_dlst **stack_a)
{
	rotate_up(stack_a);
	write(1, "ra\n", 3);
}

void	rota_rb(t_dlst **stack_b)
{
	rotate_up(stack_b);
	write(1, "rb\n", 3);
}

void	rota_rr(t_dlst **stack_a, t_dlst **stack_b)
{
	rotate_up(stack_a);
	rotate_up(stack_b);
	write(1, "rr\n", 3);
}
