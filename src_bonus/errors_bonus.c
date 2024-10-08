/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:50:53 by mkling            #+#    #+#             */
/*   Updated: 2024/10/08 14:42:32 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

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

int	is_valid_command(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0 || ft_strcmp(str, "sb\n") == 0
		|| ft_strcmp(str, "ss\n") == 0 || ft_strcmp(str, "pa\n") == 0
		|| ft_strcmp(str, "pb\n") == 0 || ft_strcmp(str, "ra\n") == 0
		|| ft_strcmp(str, "rb\n") == 0 || ft_strcmp(str, "rr\n") == 0
		|| ft_strcmp(str, "rrb\n") == 0 || ft_strcmp(str, "rra\n") == 0
		|| ft_strcmp(str, "rrr\n") == 0)
		return (1);
	return (0);
}

int	error_exit(t_dlst **stack, t_dlst **if_other_stack, char *line)
{
	if (line)
		free(line);
	if (stack)
		doublelst_clear(stack);
	if (if_other_stack)
		doublelst_clear(if_other_stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
