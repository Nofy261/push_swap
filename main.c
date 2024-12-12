/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:35:20 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/12 17:01:36 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// gerer int min et int max ❌ 
// fonction pour voir si il est deja trier  int	is_sorted_or_not(t_list *stack)  ✅ 
// Si il y a que deux chiffres fais une fonction qui fais un trie par deux (swap)  ✅ 
// creer une fonction qui fait un tri de 3 nombres ✅
// creer une fonction qui determine qui est le plus grand des nodes  ✅ 
// creer une fonction qui fait le tri de 5 ✅
// gerer le 0 envoyee en argument --> a revoir ou enlever la fonction check_error : SOLUTION testee OK ✅
// fonction swap modifiee : void au lieu de return int a la base ✅
// -g rajouter dans makefile pour gdb a enlever a la fin
// gerer l'overflow du long int 
#include <stdio.h>

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

void	sort_two(t_list **stack_a)
{
	int	i;
	
	i = ft_lstsize(*stack_a);
	if (i == 2)
		swap_nodes(stack_a, 'a');
}

void	sort_three(t_list **stack_a)
{
	t_list	*min;
	t_list	*max;

	min = find_min(*stack_a);
	max = find_max(*stack_a);
	if (ft_lstsize(*stack_a) == 3)
	{
		if ((*stack_a)->next->value == min->value && (*stack_a)->next->next->value == max->value)
			swap_nodes(stack_a, 'a');
		else if ((*stack_a)->value == max->value && (*stack_a)->next->next->value == min->value)
		{
			swap_nodes(stack_a, 'a');
			reverse_rotate(stack_a, 'a');
		}
		else if ((*stack_a)->value == max->value && (*stack_a)->next->value == min->value)
			rotate(stack_a, 'a');
		else if ((*stack_a)->value == min->value && (*stack_a)->next->value == max->value)
		{
			swap_nodes(stack_a, 'a');
			rotate(stack_a, 'a');
		}
		else if ((*stack_a)->next->value == max->value && (*stack_a)->next->next->value == min->value)
			reverse_rotate(stack_a, 'a');
	}	
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	count_b;
	t_list *min;
	
	count_b = 0;
	while(count_b < 2)
	{
		min = find_min(*stack_a);
		while (min != *stack_a) // tant que min n'est pas au debut de la liste
		{
			rotate(stack_a, 'a');
		}
		push_to_b(stack_a, stack_b);
		count_b++;
	}
	sort_three(stack_a);
	push_to_a(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
}


int	is_sorted_or_not(t_list *stack_a)
{
	while (stack_a->next != NULL)
	{		
		if (stack_a->value > stack_a->next->value)
		{
			//printf("ce n'est pas triee\n");
			return (1);
		}
		stack_a = stack_a->next;
	}
	//printf("c'est deja triee");
	return (0);	
}
// void	sort(t_list **stack_a, t_list **stack_b)
// {
// 	if (is_sorted_or_not(*stack_a) == 1) // si ce n est pas triee je trie 
// 	{
// 		if (ft_lstsize(stack_a) == 2)//ou plutot le nombre d'argument entree en parametre??
// 			sort_two(stack_a);
// 		else if (ft_lstsize(stack_a) == 3)
// 			sort_three(stack_a);
// 		else if (ft_lstsize(stack_a) == 5)
// 			sort_five(stack_a, stack_b);
// 		//else
// 		//rajouter ici radix
// 	}
// }

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
	if (is_sorted_or_not(stack_a) == 1)
	{
		if (ft_lstsize(stack_a) == 2)//ou plutot le nombre d'argument entree en parametre??
			sort_two(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sort_three(&stack_a);
		else if (ft_lstsize(stack_a) == 5)
			sort_five(&stack_a, &stack_b);
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
