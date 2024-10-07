/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkling <mkling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:56:07 by mkling            #+#    #+#             */
/*   Updated: 2024/10/07 19:01:37 by mkling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

// void	print_stack(t_dlst **stack)
// {
// 	t_dlst	*current;

// 	if (!(*stack))
// 		return ;
// 	current = (*stack);
// 	fprintf(stderr, "printing stack\n");
// 	while (current != NULL)
// 	{
// 		fprintf(stderr, "node = %d\n", current->data);
// 		current = current->next;
// 	}
// }

char	*read_till_ctrl_d(int fd)
{
	char	*total_buffer;
	char	*current_buffer;
	int		read_status;
	char	*tmp;

	total_buffer = ft_calloc(1, sizeof(char));
	if (!total_buffer)
		return (NULL);
	current_buffer = ft_calloc(42 + 1, sizeof(char));
	if (!current_buffer)
		return (NULL);
	read_status = 1;
	while (read_status > 0)
	{
		read_status = read(fd, current_buffer, 42);
		if (read_status == -1)
			return (free(current_buffer), NULL);
		current_buffer[read_status] = '\0';
		tmp = ft_strjoinfree(total_buffer, current_buffer);
		total_buffer = tmp;
	}
	free(current_buffer);
	return (total_buffer);
}

int	accumulate_cmds(char **command_list)
{
	char	*all_cmds;
	int		index;

	all_cmds = read_till_ctrl_d(0);
	command_list = ft_split(all_cmds, "\n");
	index = 0;
	while (command_list[index])
	{
		if (!is_valid_command(command_list[index]))
			return (1);
		index++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	char	**command_list;

	init_stacks(argc, argv, &stack_a, &stack_b);
	if (accumulate_cmds(command_list) == 1)
		error_exit(stack_a, stack_b, command_list);

	if (!is_sorted(stack_a))
		error_exit(stack_a, stack_b, command_list);
	ft_putstr_fd("OK\n", 1);
	doublelst_clear(stack_a);
	return (0);
}


