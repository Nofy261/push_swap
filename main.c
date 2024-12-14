/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:35:20 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/14 14:04:27 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// gerer int min et int max ❌ 
// gerer le 0 envoyee en argument --> a revoir ou enlever la fonction check_error : SOLUTION testee OK ✅
// fonction swap modifiee : void au lieu de return int a la base ✅
// gerer l'overflow du long int ❌ 
// regler le dernier nombre qui reste dans b a la fin ❌
// radix ne gere pas les negatifs
// verifier qui doit etre static ou pas ❌
// printf a enlever dans la fonction int is_sorted_or_not

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	char **cut_argv;
	t_list *stack_a;
	t_list *stack_b;
	
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	cut_argv = NULL;
	
	if (verif_argc(argc) == 1 || check_sign(argv) == 1) //Si aucun paramètre n’est spécifié, le programme ne doit rien afficher et rendre l’invite de commande.(cf sujet) 
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
	set_rank(&stack_a);
	if (is_sorted_or_not(stack_a) == 1)
	{
		if (ft_lstsize(stack_a) == 2)
			sort_two(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sort_three(&stack_a);
		else if (ft_lstsize(stack_a) == 5)
			sort_five(&stack_a, &stack_b);
		else
			radix_sort(&stack_a, &stack_b);
	}
	printf("Liste A:\n");
	while (stack_a)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("Liste B:\n");
	while (stack_b)
	{
		printf("%d\n", stack_b->value);
		stack_b = stack_b->next;
	}
}
