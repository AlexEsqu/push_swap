/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:07:30 by mkling            #+#    #+#             */
/*   Updated: 2024/09/30 17:25:08 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort_to_nearest_rotation(t_dlst **stack)
{
	t_dlst	*max;
	t_dlst	*min;
	t_dlst	*top;
	t_dlst	*middle;
	t_dlst	*bottom;

	max = find_biggest_num_in_stack(*stack);
	min = find_smallest_num_in_stack(*stack);
	top = (*stack);
	middle = (*stack)->next;
	bottom = (*stack)->next->next;
	if ((bottom == max && middle == min)
		|| (top == max && bottom == min)
		|| (middle == max && top == min))
		swap_top(stack, NULL);
}

void	tiny_sort(t_dlst **stack)
{
	tiny_sort_to_nearest_rotation(stack);
	rotate_to_top(stack, find_smallest_num_in_stack(*stack));
}
