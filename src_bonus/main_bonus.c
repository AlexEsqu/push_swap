/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:56:07 by mkling            #+#    #+#             */
/*   Updated: 2024/10/08 11:06:14 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	char	*line;

	init_stacks(argc, argv, &stack_a, &stack_b);
	line = get_next_line(0);
	while (line)
	{
		parse_command(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (!is_sorted(stack_a) || (stack_b) != NULL)
		error_exit(stack_a, stack_b, line);
	ft_putstr_fd("OK\n", 1);
	doublelst_clear(stack_a);
	return (0);
}

// void	print_stack(t_dlst **stack)
// {
// 	t_dlst	*current;

// 	if (!(*stack))
// 		return ;
// 	current = (*stack);
// 	fprintf(stderr, "printing stack %c\n", (*stack)->stack_id);
// 	while (current != NULL)
// 	{
// 		fprintf(stderr, "node = %d\n", current->data);
// 		current = current->next;
// 	}
// }

// void	print_both_stacks(t_dlst **a, t_dlst **b)
// {
// 	fprintf(stderr, "\nPRINT\n");
// 	print_stack(a);
// 	print_stack(b);
// }
