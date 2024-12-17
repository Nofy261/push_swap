/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:21:12 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/17 18:15:29 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sign(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == '-' || argv[j][i] == '+')
			{
				if (!ft_isdigit(argv[j][i + 1]))
					return (1);
			}
			if (argv[j][0] == 32 && (argv[j][1] == 32 || argv[j][1] == '\0'))
				return (1);
			i++;
		}
		if (i == 0)
			return (1);
		j++;
	}
	return (0);
}

void	parse_arguments(t_list **stack_a, char **big_argv)
{
	t_list	*newnode;
	int		j;
	int		value;

	j = 0;
	while (big_argv[j])
	{
		value = ft_atoi(big_argv[j], stack_a, big_argv);
		newnode = ft_lstnew(value);
		ft_lstadd_back(stack_a, newnode);
		j++;
	}
}

int	check_double(t_list *stack_a, char **cut_argv)
{
	t_list	*node;
	t_list	*next_node;

	node = stack_a;
	while (node)
	{
		next_node = node->next;
		while (next_node)
		{
			if (node->value == next_node->value)
				print_error(cut_argv, &stack_a);
			next_node = next_node->next;
		}
		node = node->next;
	}
	return (0);
}
