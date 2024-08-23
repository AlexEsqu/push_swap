/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:02:15 by mkling            #+#    #+#             */
/*   Updated: 2024/08/23 15:23:49 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_nbr_in_linklist(char *nbr, t_node *stack)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (-1);
	node->data = ft_atoi(nbr);
	ft_lstadd_front(&stack, node);
	return (0);
}

int	wrangle_input(int argc, char **argv, t_node *initial_stack)
{
	char	**input_array;
	int		i;

	if (argc < 2)
		return (-1);
	if (argc == 2)
	{
		i = 0;
		input_array = ft_split(argv[1], ' ');
		while (input_array[i] != NULL)
		{
			if (put_nbr_in_linklist(input_array[i], initial_stack) == -1)
				return (-1);
			i++;
		}
	}
	if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			if (put_nbr_in_linklist(argv[i], initial_stack) == -1)
				return (-1);
			i++;
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
	t_node	initial_stack;

	if (wrangle_input(argc, argv, &initial_stack) == -1)
		return (-1);
	ft_lstiter(&initial_stack, print_list);
	return (0);
}
