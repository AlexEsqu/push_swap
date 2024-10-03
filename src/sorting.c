/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:49:47 by mkling            #+#    #+#             */
/*   Updated: 2024/10/03 10:48:55 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cost_to_top(t_dlst *node, int stack_len)
{
	int	cost;

	if (node->is_above_median)
		cost = node->index;
	else
		cost = stack_len - node->index;
	return (cost);
}

static void	opti_double_rota(t_dlst *a, int len_a, int len_b)
{
	int		rrr_cost;
	int		rrev_cost;
	t_dlst	*b;

	a->opti = NONE;
	b = a->target;
	rrr_cost = ft_min(a->index, b->index)
		+ (ft_max(a->index, b->index) - ft_min(a->index, b->index));
	if ((len_b - b->index) > (len_a - a->index))
		rrev_cost = (len_a - a->index) + ((len_b - b->index)
				- (len_a - a->index));
	if ((len_b - b->index) < (len_a - a->index))
		rrev_cost = (len_b - b->index) + ((len_a - a->index)
				- (len_b - b->index));
	if ((rrr_cost < a->push_cost + 1))
	{
		a->push_cost = rrr_cost + 1;
		a->opti = ROT_UP;
	}
	if ((rrev_cost < a->push_cost + 1))
	{
		a->push_cost = rrev_cost + 1;
		a->opti = REV_DO;
	}
}

void	set_push_cost(t_dlst *src, t_dlst *dest)
{
	int	len_src;
	int	len_dest;

	len_src = stack_len(src);
	len_dest = stack_len(dest);
	set_index(src, dest);
	while (src)
	{
		src->push_cost = cost_to_top(src, len_src)
			+ cost_to_top(src->target, len_dest);
		if (src->is_above_median == src->target->is_above_median)
			src->push_cost = ft_max(cost_to_top(src, len_src),
					cost_to_top(src->target, len_dest));
		src = src->next;
	}
}

static t_dlst	*get_cheapest_move(t_dlst *a)
{
	t_dlst	*cheap;

	cheap = a;
	while (a)
	{
		if (a->push_cost < cheap->push_cost)
			cheap = a;
		a = a->next;
	}
	return (cheap);
}

void	push_cheapest(t_dlst **src, t_dlst **dest)
{
	t_dlst	*cheap;

	if ((*src)->stack_id == 'a')
		cheap = get_cheapest_move(*src);
	else
		cheap = (*src);
	while ((*src) != cheap && (*dest) != cheap->target)
	{
		if (cheap->is_above_median && cheap->target->is_above_median)
			rotate_up(src, dest);
		else if (!cheap->is_above_median && !cheap->target->is_above_median)
			rotate_down(src, dest);
		else if (cheap->index == 1 && cheap->target->index == 1)
			swap_top(src, dest);
		else
			break ;
	}
	rotate_to_top(src, cheap);
	rotate_to_top(dest, cheap->target);
	push_top(src, dest);
}

void	mecha_turk_sort(t_dlst **stack_a, t_dlst **stack_b)
{
	while (stack_len(*stack_a) > 3 && stack_len(*stack_b) < 2)
		push_top(stack_a, stack_b);
	while (stack_len(*stack_a) > 3)
	{
		set_index(*stack_a, *stack_b);
		set_target_closest_smaller(*stack_a, *stack_b);
		set_push_cost(*stack_a, *stack_b);
		push_cheapest(stack_a, stack_b);
	}
	tiny_sort_to_nearest_rotation(stack_a);
	while (stack_len(*stack_b) > 0)
	{
		set_index(*stack_a, *stack_b);
		set_target_closest_bigger(*stack_b, *stack_a);
		push_cheapest(stack_b, stack_a);
	}
	rotate_to_top(stack_a, find_smallest_num_in_stack(*stack_a));
}
