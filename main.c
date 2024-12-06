/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:35:20 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/06 12:12:13 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// gerer int min et int max ❌ 

// fonction pour voir si il est deja trier  int	is_sorted(t_list *stack)  ❌ 
// appel ft_lstsize pour voir le nombre de node que contient la liste chainee 
// et stock le retour dans un int ❌ 
// Si il y a que deux chiffres fais une fonction qui fais un trie par deux (swap)

#include <stdio.h>

//dans la pile a , il y a des nodes, je dois verifier si les nodes sont trier ou pas
//fonction qui compare les nodes, 








int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	char **cut_argv;
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	cut_argv = NULL;
	if (verif_argc(argc) == 1 || check_sign(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		cut_argv = ft_split(argv[i], ' ');
		parse_arguments(&stack_a, cut_argv);	
		i++;
	}
	check_double(&stack_a);
}


