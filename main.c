/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:35:20 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/18 16:53:48 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**cut_argv;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	cut_argv = NULL;
	if (argc == 1)
		return (1);
	if (check_sign(argv) == 1)
		ft_putstr_fd_exit("Error\n", 2);
	while (i < argc)
	{
		cut_argv = ft_split(argv[i], ' ');
		parse_arguments(&stack_a, cut_argv);
		free_all(cut_argv);
		i++;
	}
	check_double(stack_a);
	normalisation(stack_a);
	check_sort(&stack_a, &stack_b);
	free_end(&stack_a, &stack_b);
}
