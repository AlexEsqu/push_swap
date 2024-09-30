/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:07:30 by mkling            #+#    #+#             */
/*   Updated: 2024/09/30 17:13:45 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_dlst **stack)
{
	if ((*stack) == find_biggest_num_in_stack(*stack))
	{
		if ((*stack)->next == find_smallest_num_in_stack(*stack))
			rotate_up(stack, NULL);
		else
		{
			swap_top(stack, NULL);
			rotate_down(stack, NULL);
		}
	}
	else if ((*stack)->next == find_biggest_num_in_stack(*stack))
	{
		if ((*stack)->next->next == find_smallest_num_in_stack(*stack))
			rotate_down(stack, NULL);
		else
		{
			swap_top(stack, NULL);
			rotate_up(stack, NULL);
		}
	}
	if ((*stack)->data > (*stack)->next->data)
		swap_top(stack, NULL);
}
