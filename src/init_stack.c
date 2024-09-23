/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:38:35 by mkling            #+#    #+#             */
/*   Updated: 2024/09/23 13:45:51 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlst	*doublelst_new(int content)
{
	t_dlst	*node;

	node = malloc(sizeof(t_dlst));
	if (!node)
		return (NULL);
	node->data = content;
	node->next = NULL;
	node->prev = NULL;
	node->e_stack = STACK_A;
	return (node);
}

void	put_nbr_at_bottom_stack(char *nbr, t_dlst **stack)
{
	t_dlst	*node;
	long	num;

	num = ft_atol(nbr);
	if (is_overflow(num) || is_duplicate(*stack, (int)num)
		|| contains_non_digit(nbr))
		error_exit(*stack);
	node = doublelst_new(num);
	if (!node)
		error_exit(*stack);
	add_on_bottom_of_stack(stack, node);
}

void	init_stacks(int argc, char **argv, t_dlst **stack_a, t_dlst **stack_b)
{
	int		i;
	char	**input_array;

	i = 0;
	(*stack_a) = NULL;
	(*stack_b) = NULL;
	if (argc < 2 || argv[1][0] == '\0')
		exit(1);
	if (argc == 2)
		input_array = ft_split(argv[1], ' ');
	if (argc > 2)
		input_array = &argv[1];
	if (!input_array)
		error_exit(NULL);
	while (input_array[i] != NULL)
		put_nbr_at_bottom_stack(input_array[i++], stack_a);
}
