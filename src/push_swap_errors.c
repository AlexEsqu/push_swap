/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:50:53 by mkling            #+#    #+#             */
/*   Updated: 2024/08/26 14:48:20 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i++] != NULL)
		free(array[i]);
	free(array);
}

void	free_list(t_node **linked_list, void (*free)(void *))
{
	t_node	*next;
	t_node	*current;

	current = *linked_list;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*linked_list = NULL;
}

/*int	self_destruct(t_node *stack, char **argv)
{

}*/
