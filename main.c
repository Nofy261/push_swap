/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:35:20 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/07 15:17:19 by nolecler         ###   ########.fr       */
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

// = 1 veut dire que ce n'est pas triee -> Donc creer une fonction qui va trier = ALGORITHME ❌
// = 0 veut dire que c'est triee

//Si aucun paramètre n’est spécifié, le programme ne doit rien afficher et rendre l’invite de commande.(cf sujet) 

int	is_sorted(t_list *stack_a)
{
	while (stack_a->next != NULL)
	{		
		if (stack_a->value > stack_a->next->value)
		{
			printf("ce n'est pas triee");
			return (1);
		}
		stack_a = stack_a->next;
	}
	printf("c'est deja triee");
	return (0);	
}

void	sort_2(t_list *stack_a)
{
	int	i;
	
	i = ft_lstsize(stack_a);
	if (i == 2)
		swap_nodes(&stack_a, 'a');
}
//creer une fonction qui determine qui est le plus grand des nodes

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
		if(stack_a->value < stack_a->next->value)
			max = stack_a->next;
		stack_a = stack_a->next;
	}
	return (max);
}





//creer une fonction qui trie 3nombres
void	sort_3(t_list **stack_a)
{
	int	i;
	int	position;
	
	position = 0;// ou 1??
	i = ft_lstsize(stack_a);
	t_list	*node = *stack_a;
	
	if (i == 3)
	{
		//si node2 est en debut de la liste et node3 a la fin de la liste
		//--> "sa"

		// si node3 est au debut et node1 a la fin 
		//--> "sa" puis "rra"

		//si node3 au debut et node2 a la fin
		// --> "ra"
		
		//si node1 au debut et node2 a la fin
		//--> "sa" puis "ra"

		//si node1 a la fin et node2 au debut
		//--> "rra"
	}
	

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
	}
}


