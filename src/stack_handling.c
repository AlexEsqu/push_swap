/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:13:01 by alex              #+#    #+#             */
/*   Updated: 2024/10/03 11:37:44 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top(t_dlst **stack, t_dlst *node)
{
	set_index(*stack, NULL);
	while ((*stack)->data != node->data)
	{
		if (node->is_above_median)
			rotate_up(stack, NULL);
		else
			rotate_down(stack, NULL);
	}
}

t_dlst	*doublelst_new(int content)
{
	t_dlst	*node;

	node = malloc(sizeof(t_dlst));
	if (!node)
		return (NULL);
	node->data = content;
	node->next = NULL;
	node->prev = NULL;
	node->stack_id = 'a';
	return (node);
}

void	put_nbr_at_bottom_stack(char *nbr, t_dlst **stack)
{
	t_dlst	*node;
	long	num;

	num = ft_atol(nbr);
	if (is_overflow(num) || is_duplicate(*stack, num)
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
	if ((argc < 2 || argv[1][0] == '\0')
		|| (argc == 2 && countword(argv[1], ' ') < 2))
		exit(1);
	if (argc == 2)
		input_array = ft_split(argv[1], ' ');
	if (argc > 2)
		input_array = &argv[1];
	if (!input_array)
		exit(1);
	while (input_array[i] != NULL)
		put_nbr_at_bottom_stack(input_array[i++], stack_a);
	if (argc == 2)
		ft_free_tab(input_array);
}
