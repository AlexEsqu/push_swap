/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_link_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:38:35 by mkling            #+#    #+#             */
/*   Updated: 2024/09/18 17:23:53 by mkling           ###   ########.fr       */
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
	return (node);
}

void	put_nbr_at_bottom_stack(char *nbr, t_dlst **stack)
{
	t_dlst	*node;
	long	num;

	num = ft_atoi(nbr);
	node = doublelst_new(num);
	if (!node || is_overflow(num) || is_duplicate(stack, num))
		error_exit(*stack);
	add_on_bottom_of_stack(stack, node);
}

t_dlst	*init_stack(int argc, char **argv)
{
	int		i;
	char	**input_array;
	t_dlst	*stack;

	i = 0;
	stack = NULL;
	if (argc < 2)
		error_exit(NULL);
	if (argc == 2)
		input_array = ft_split(argv[1], ' ');
	if (argc > 2)
		input_array = &argv[1];
	if (!input_array)
		error_exit(NULL);
	while (input_array[i] != NULL)
		put_nbr_at_bottom_stack(input_array[i++], &stack);
	return (stack);
}
