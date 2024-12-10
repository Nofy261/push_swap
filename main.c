/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:35:20 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/10 16:14:45 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// gerer int min et int max ❌ 
// fonction pour voir si il est deja trier  int	is_sorted(t_list *stack)  ✅ 
// Si il y a que deux chiffres fais une fonction qui fais un trie par deux (swap)  ✅ 
// creer une fonction qui fait un tri de 3 nombres ✅
// creer une fonction qui determine qui est le plus grand des nodes  ✅ 
// gerer le 0 envoyee en argument ❌

#include <stdio.h>


void	sort_2(t_list *stack_a)
{
	int	i;
	
	i = ft_lstsize(stack_a);
	if (i == 2)
		swap_nodes(&stack_a, 'a');
}

static	t_list    *find_max(t_list *stack_a)
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

static	t_list    *find_min(t_list *stack_a)
{
	t_list *min = stack_a; //les deux pointent vers un meme maillon
	
	while(stack_a)
	{
		if(stack_a->value < min->value)
			min = stack_a;
		stack_a = stack_a->next;
	}
	return (min);
}

void	sort_3(t_list *stack_a)
{
	t_list	*min;
	t_list	*max;

	min = find_min(stack_a);
	max = find_max(stack_a);
	if (ft_lstsize(stack_a) == 3)
	{
		if (stack_a->next->value == min->value && stack_a->next->next->value == max->value)
			swap_nodes(&stack_a, 'a');
		else if (stack_a->value == max->value && stack_a->next->next->value == min->value)
		{
			swap_nodes(&stack_a, 'a');
			reverse_rotate(&stack_a, 'a');
		}
		else if (stack_a->value == max->value && stack_a->next->value == min->value)
			rotate(&stack_a, 'a');
		else if (stack_a->value == min->value && stack_a->next->value == max->value)
		{
			swap_nodes(&stack_a, 'a');
			rotate(&stack_a, 'a');
		}
		else if (stack_a->next->value == max->value && stack_a->next->next->value == min->value)
			reverse_rotate(&stack_a, 'a');
	}
	
}
// creer une fonction qui fait un tri de 5 nombres ❌

// Tri de 5 : trouver les 2 pplus petits, les push dans b, tri de 3 de stack_a, ❌
			//si le 1er chiffre dans stack_b est plus grand que le 2eme , pa 2fois sinon sb et pa 2fois ❌

void	sort_5(t_list *stack_a, t_list *stack_b)
{
	







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
		//si stack_a = 2 nombres
		sort_2(stack_a);
		//si stack_a = 
		sort_3(stack_a);
		//sort_5(stack_a, stack_b);
	}
}


