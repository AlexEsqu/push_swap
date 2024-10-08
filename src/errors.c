/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:50:53 by mkling            #+#    #+#             */
/*   Updated: 2024/10/07 02:45:27 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_overflow(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

int	is_duplicate(t_dlst *stack, int num)
{
	if (stack == 0)
		return (0);
	while (stack)
	{
		if (stack->data == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	contains_non_digit(char *str)
{
	int	sign;

	sign = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = 1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		sign = 0;
		str++;
	}
	return (sign);
}

int	error_exit(t_dlst *stack)
{
	if (stack)
		doublelst_clear(stack);
	write(2, "Error\n", 6);
	exit(1);
}
