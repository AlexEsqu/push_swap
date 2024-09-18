/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:02:15 by mkling            #+#    #+#             */
/*   Updated: 2024/09/18 17:23:18 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_dlst **stack)
{
	t_dlst	*current;

	current = (*stack);
	fprintf(stderr, "printing stack\n");
	while (current != NULL)
	{
		fprintf(stderr, "node = %d\n", current->data);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;

	stack_a = init_stack(argc, argv);
	stack_b = NULL;
	print_stack(&stack_a);
	rota_ra(&stack_a);
	print_stack(&stack_a);
	rrev_rra(&stack_a);
	print_stack(&stack_a);
	return (0);
}
