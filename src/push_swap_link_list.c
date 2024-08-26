/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_link_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:38:35 by mkling            #+#    #+#             */
/*   Updated: 2024/08/26 14:47:26 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last_node(t_node *lst)
{
	t_node	*iteri;

	iteri = lst;
	while (iteri)
		iteri = iteri->next;
	return (iteri);
}

void	append_node_to_stack(t_node **stack, t_node *node)
{
	t_node	*last_node;

	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	put_nbr_in_linklist(char *nbr, t_node **stack)
{
	t_node	*node;
	long	num;

	if (stack == NULL)
		return (0);
	num = ft_atoi(nbr);
	node = malloc(sizeof(t_node));
	if (!node || num > INT_MAX || num < INT_MIN)
		return (-1);
	node->data = num;
	node->next = NULL;
	append_node_to_stack(stack, node);
	return (0);
}
