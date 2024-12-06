/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:21:12 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/06 10:14:49 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int verif_argc(int argc) //s'il y a juste un argument
{
	if (argc <= 1)
	{
		write (1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	check_sign(char **argv) // on regarde si apres le - ou + c'est bien un chiffre 
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		i = 0;
		while(argv[j][i])
		{
			if(argv[j][0] == '-' || argv[j][0] == '+')
			{
				if(!ft_isdigit(argv[j][i + 1]))
					return (1);
			}
			if (argv[j][0] == 32 && (argv[j][1] == 32 || argv[j][1] == '\0'))
				return (0);
			i++;//on va checker les autres chiffres/caractere?
		}
		//j++; a rajouter ou pas??
	}
	if (i == 0)
		return (1);
	j++;
	return(0);
}

void	check_errors(char *str) //cas ++++++667778764
{	
	if (ft_atoi(str) == 0) // si atoi retourne 0; //a voir car si +7ab56 : atoi retourne 7;
	{
		write (1, "Error\n", 6);
		return ; // on arrete le programme;
	}
	//else ?? necessaire ou pas??
}

void	parse_arguments(t_list **stack_a, char **big_argv)// on met les nodes qui sont donnes en argument dans la stack_a
{
	int	i;
	int	j;
	int	value;
	t_list *newnode;
	//t_list *stack_a = NULL; : non necessaire 
	
	value = 0;
	i = 0;
	j = 1;
	while (big_argv[j])
	{
		i = 0;
		while (big_argv[j][i])
		{
			check_errors(big_argv[j]);
			//rajouter la fonction check_sign ici ??
			value = ft_atoi(big_argv[j]);
			newnode = ft_lstnew(value); //creer un noeud
			ft_lstadd_back(stack_a, newnode); //place le noeud dans la liste
			//i++; //?? qu'est ce qu'on incremente ici?
		}
		j++;
	}
}

int	check_double(t_list **stack_a) //test ok
{
	t_list *node = *stack_a;
	while (node)
	{
		t_list *next_node = node->next;
		while(next_node)
		{
			if (node->value == next_node->value)
			{
				return (1);
			}
			next_node = next_node->next; 
		}
		node = node->next;
	}
	return (0);
}