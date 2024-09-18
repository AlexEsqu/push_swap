/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:40:38 by mkling            #+#    #+#             */
/*   Updated: 2024/09/18 14:09:26 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *num1, int *num2)
{
	int	tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void	swap_top(t_dlst **stack)
{
	if ((*stack) == NULL | (*stack)->next == NULL)
		return ;
	ft_swap(&(*stack)->data, &(*stack)->next->data);
}

void	swap_sa(t_dlst **stack_a)
{
	swap_top(stack_a);
	write(1, "sa\n", 3);
}

void	swap_sb(t_dlst **stack_b)
{
	swap_top(stack_b);
	write(1, "sb\n", 3);
}

void	swap_ss(t_dlst **stack_a, t_dlst **stack_b)
{
	swap_top(stack_a);
	swap_top(stack_b);
	write(1, "ss\n", 3);
}
