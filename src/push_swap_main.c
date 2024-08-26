/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:02:15 by mkling            #+#    #+#             */
/*   Updated: 2024/08/26 14:46:32 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_already_in_stack(t_node **stack, int num)
{
	t_node	*itering;

	itering = NULL;
	if (*stack == 0)
		return (0);
	while (itering)
	{
		if (itering->data == num)
			return (1);
	}
	return (0);
}

int	wrangle_input(int argc, char **argv, t_node *initial_stack)
{
	char	**input_array;
	int		i;

	if (argc == 2)
	{
		i = 0;
		input_array = ft_split(argv[1], ' ');
		while (input_array[i++] != NULL)
		{
			if (put_nbr_in_linklist(input_array[i], &initial_stack) == -1)
				return (-1);
		}
	}
	if (argc > 2)
	{
		i = 1;
		while (argc > i++)
		{
			if (put_nbr_in_linklist(argv[i], &initial_stack) == -1)
				return (-1);
		}
	}
	return (0);
}

void	print_list(int *num)
{
	fprintf(stderr, "node = %d\n", *num);
}

int	main(int argc, char **argv)
{
	t_node	*initial_stack;
	//t_node	*sorted_stack;

	initial_stack = NULL;
	if (argc < 2 || wrangle_input(argc, argv, initial_stack) == -1)
		return (-1);
	return (0);
}
