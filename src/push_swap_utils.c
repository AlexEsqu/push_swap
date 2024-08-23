/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:34:35 by mkling            #+#    #+#             */
/*   Updated: 2024/08/23 15:13:50 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	number;

	i = 0;
	minus = -1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = minus * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 - (str[i] - '0');
		i++;
	}
	return (number * minus);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	(*lst) = new;
}

void	ft_lstiter(t_node *lst, void (*f)(int *))
{
	t_node	*iteri;

	iteri = lst;
	while (iteri)
	{
		(*f)(&iteri->data);
		iteri = iteri->next;
	}
}

static void	ft_bzero(void *ptr, unsigned long len)
{
	unsigned char	*str;

	str = ptr;
	while (len--)
		*str++ = 0;
}

void	*ft_calloc(size_t nbr, size_t size)
{
	void	*result;

	if (nbr == 0 || size == 0 || ((size_t) - 1 / nbr) < size)
		return (malloc(0));
	result = malloc(nbr * size);
	if (!result)
		return (NULL);
	ft_bzero(result, nbr * size);
	return (result);
}
