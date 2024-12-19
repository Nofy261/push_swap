/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:12:08 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/19 09:29:46 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *stack_a)
{
	t_list	*tmp;

	while (stack_a)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
}

void	*free_all(char **str)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void	free_end(t_list **stack_a, t_list **stack_b)
{
	free_list(*stack_a);
	free_list(*stack_b);
}

void	print_error(char **cut_argv, t_list **stack_a)
{
	write (2, "Error\n", 6);
	free_all(cut_argv);
	free_list(*stack_a);
	exit(EXIT_FAILURE);
}
