/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:02:12 by mkling            #+#    #+#             */
/*   Updated: 2024/08/23 15:14:07 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node {
	int				data;
	struct s_node	*next;
}	t_node;

char	**ft_split(char const *s, char sep);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstiter(t_node *lst, void (*f)(int *));
void	*ft_calloc(size_t nbr, size_t size);

#endif
