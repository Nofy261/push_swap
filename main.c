/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:35:20 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/17 13:18:24 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// gerer l'overflow du long int ❌ 
// Quand on ne met rien en argument, la fonction ne doit rien renvoyer meme pas Error  
// verifier qui doit etre static ou pas ❌
// "0 -4 - 88 9" =  Error
// Revoir atoi car trop longue


void    free_list(t_list *stack_a)
{
    t_list    *tmp;

    while (stack_a)
    {
        tmp = stack_a;
        stack_a = stack_a->next;
        free(tmp);
    }
}

static void	*free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

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
	
	//  if (argc == 1) // RAJOUT s'il n'y a pas d argument on ne renvoie rien
	//  	return (1);
	//A REVOIR 
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
	// ici 
	check_double(&stack_a);
	set_rank(&stack_a);
	if (!is_sorted_or_not(stack_a))// ou if (is_sorted_or_not(stack_a) == 0)
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
	free_all(cut_argv);
	free_list(stack_a);
	
	//printf("Liste A:\n");
	//while (stack_a)
	//{
		//printf("%d\n", stack_a->value);
	//	stack_a = stack_a->next;
	//}
	//printf("Liste B:\n");
	//while (stack_b)
	//{
		//printf("%d\n", stack_b->value);
	//	stack_b = stack_b->next;
	//}
}
