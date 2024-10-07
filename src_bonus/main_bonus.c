/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:56:07 by mkling            #+#    #+#             */
/*   Updated: 2024/10/07 02:43:17 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	char	*line;

	init_stacks(argc, argv, &stack_a, &stack_b);
	while (line != NULL)
	{
		line = get_next_line(0);
		if (!is_valid_command(line))
			error_exit(stack_a, stack_b);
		if (line[0] == 's')
			swap_top(&stack_a, &stack_b, line);
		if (line[0] == 'p')
			push_top(&stack_a, &stack_b, line);
		if (line[0] == 'r' && line[1] != 'r')
			rotate_up(&stack_a, &stack_b, line);
		else if (line[0] == 'r')
			rotate_down(&stack_a, &stack_b, line);
	}
	if (!is_sorted(stack_a))
		error_exit(stack_a, stack_b);
	ft_putstr_fd("OK\n", 1);
	doublelst_clear(stack_a);
	return (0);
}
