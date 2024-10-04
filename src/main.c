/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:02:15 by mkling            #+#    #+#             */
/*   Updated: 2024/10/04 20:18:12 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;

	init_stacks(argc, argv, &stack_a, &stack_b);
	if (!is_sorted(stack_a))
	{
		if (stack_len(stack_a) <= 3)
			tiny_sort(&stack_a);
		else
			mecha_turk_sort(&stack_a, &stack_b);
	}
	doublelst_clear(stack_a);
	fprintf(stderr, "done\n");
	return (0);
}

// void	print_stack(t_dlst **stack)
// {
// 	t_dlst	*current;

// 	if (!(*stack))
// 		return ;
// 	current = (*stack);
// 	fprintf(stderr, "printing stack\n");
// 	while (current != NULL)
// 	{
// 		fprintf(stderr, "node = %d\n", current->data);
// 		current = current->next;
// 	}
// }

// void	print_both_stacks(t_dlst **a, t_dlst **b)
// {
// 	print_stack(a);
// 	print_stack(b);
// }
