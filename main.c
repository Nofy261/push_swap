/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:35:20 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/10 12:55:11 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// gerer int min et int max ❌ 

// fonction pour voir si il est deja trier  int	is_sorted(t_list *stack)  ✅ 
// appel ft_lstsize pour voir le nombre de node que contient la liste chainee 
// et stock le retour dans un int ❌ 
// Si il y a que deux chiffres fais une fonction qui fais un trie par deux (swap)  ✅ 
// creer une fonction qui fait un tri de 3 nombres

#include <stdio.h>


void	sort_2(t_list *stack_a)
{
	int	i;
	
	i = ft_lstsize(stack_a);
	if (i == 2)
		swap_nodes(&stack_a, 'a');
}
//creer une fonction qui determine qui est le plus grand des nodes  ✅ 

// Définir une variable max = premier élément de la pile.
// Tant qu'il reste des éléments dans la pile :
// a. Comparer la valeur de l'élément courant avec la valeur de max.
// b. Si la valeur de l'élément courant est plus grande :
// i. Mettre max à jour avec cet élément.
// c. Passer à l'élément suivant.
// Retourner max.

t_list    *find_max(t_list *stack_a)
{
	t_list *max = stack_a;
	
	while(stack_a)
	{
		if(stack_a->value > max->value)
			max = stack_a;
		stack_a = stack_a->next;
	}
	return (max);
}
t_list    *find_min(t_list *stack_a)
{
	t_list *min = stack_a; //les deux pointent vers un meme maillon
	//t_list *min = *stack_a; = acces a la valeur du maillon pointee par stack_a
	
	while(stack_a)
	{
		if(stack_a->value < min->value)
			min = stack_a;
		stack_a = stack_a->next;
	}
	return (min);
}

//creer une fonction qui trie 3nombres
void	sort_3(t_list *stack_a)
{
	int	i;
	t_list	*min;
	t_list	*max;

	min = find_min(stack_a);
	max = find_max(stack_a);
	i = ft_lstsize(stack_a);
	//t_list	*node = stack_a; //node et stack_a pointe vers le meme maillon

	//Un pointeur qui pointe vers le premier element de la liste
	//un pointeur qui pointe vers le max
	//un pointeur qui pointe le min

	if (i == 3)
	{
		//si max est a la fin et min au milieu : sa
		

		//si max au debut et min a la fin : sa puis rra
		

		//si max au debut et min au milieu : ra
		//if (stack_a->value == max->value && stack_a->next->value == min->value)
		//	rotate(&stack_a, 'a');
					
		
		
		//si min au debut et max au milieu : sa puis ra
		if (stack_a->value == min->value && stack_a->next->value == max->value)
		{
			swap_nodes(&stack_a, 'a');
			rotate(&stack_a, 'a');
		}

		//si max au milieu et min a la fin : rra
		
	}
}


// = 1 veut dire que ce n'est pas triee -> Donc creer une fonction qui va trier = ALGORITHME ❌
// = 0 veut dire que c'est triee

//Si aucun paramètre n’est spécifié, le programme ne doit rien afficher et rendre l’invite de commande.(cf sujet) 

int	is_sorted(t_list *stack_a)
{
	while (stack_a->next != NULL)
	{		
		if (stack_a->value > stack_a->next->value)
		{
			printf("ce n'est pas triee\n");
			sort_2(stack_a);
			sort_3(stack_a);
			return (1);
		}
		stack_a = stack_a->next;
	}
	printf("c'est deja triee");
	return (0);	
}

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
	if (is_sorted(stack_a) == 1)
	{
		sort_2(stack_a);
		sort_3(stack_a);
	}
}


