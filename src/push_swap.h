/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:02:12 by mkling            #+#    #+#             */
/*   Updated: 2024/08/26 14:45:32 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node {
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*last;
}	t_node;

char	**ft_split(char const *s, char sep);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nbr, size_t size);
int		put_nbr_in_linklist(char *nbr, t_node **stack);

#endif
