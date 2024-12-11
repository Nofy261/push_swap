/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:35:20 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/11 12:24:07 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// gerer int min et int max ❌ 
// fonction pour voir si il est deja trier  int	is_sorted(t_list *stack)  ✅ 
// Si il y a que deux chiffres fais une fonction qui fais un trie par deux (swap)  ✅ 
// creer une fonction qui fait un tri de 3 nombres ✅
// creer une fonction qui determine qui est le plus grand des nodes  ✅ 
// creer une fonction qui fait le tri de 5 ✅
// gerer le 0 envoyee en argument ❌

#include <stdio.h>

void	sort_two(t_list *stack_a)
{
	int	i;
	
	i = ft_lstsize(stack_a);
	if (i == 2)
		swap_nodes(&stack_a, 'a');
	//return ;
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

void	sort_three(t_list *stack_a)
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

void	sort_five(t_list *stack_a, t_list *stack_b)
{
	int	count_b;
	t_list *min;
	
	count_b = 0;
	while(count_b < 2)
	{
		min = find_min(stack_a);
		while (min != stack_a) // tant que min n'est pas au debut de la liste
		{
			rotate(&stack_a, 'a');
		}
		push_to_b(&stack_a, &stack_b); 
		count_b++;
	}
	sort_three(stack_a);
	push_to_a(&stack_a, &stack_b);
	push_to_a(&stack_a, &stack_b);
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
	char **cut_argv;
	t_list *stack_a;
	t_list *stack_b;
	
	i = 1;
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
		//sort_two(stack_a);
		//sort_three(stack_a);
		sort_five(stack_a, stack_b); //cas d 3 1 2 -1 4 ne fonctionne pas
	}
}


