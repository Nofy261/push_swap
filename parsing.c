/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teddybandama <teddybandama@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:21:12 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/15 19:19:52 by teddybandam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int verif_argc(int argc) //s'il y a juste un argument
{
	if (argc <= 1)
		return (1);
	return (0);
}


int	check_sign(char **argv) // on regarde si apres le - ou + c'est bien un chiffre 
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while(argv[j][i])
		{
			if(argv[j][i] == '-' || argv[j][i] == '+')
			{
				if(!ft_isdigit(argv[j][i + 1]))
					return (1);
			}
			if (argv[j][0] == 32 && (argv[j][1] == 32 || argv[j][1] == '\0'))
				return (1);
			i++;//on va checker les autres chiffres/caractere?
		}
		if (i == 0)
			return (1);
		j++;
	}
	return(0);
}

void	parse_arguments(t_list **stack_a, char **big_argv)// on met les nodes qui sont donnes en argument dans la stack_a
{
	t_list *newnode;
	int	j;
	int value;
	
	j = 0;
	while (big_argv[j])
	{
		value = ft_atoi(big_argv[j]);
		newnode = ft_lstnew(value);
		ft_lstadd_back(stack_a, newnode);//pourquoi rajouter a la fin et non au debut??
		j++; 
	}
}


int	check_double(t_list **stack_a) //test ok
{
	t_list *node = *stack_a;// ecriture valable ou d'abord initialiser et ensuite donner la valeur?? Il ne faut pas enlever * devant stack_a????
	while (node)
	{
		t_list *next_node = node->next;
		while(next_node)
		{
			if (node->value == next_node->value)
			{
				write (2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			next_node = next_node->next; 
		}
		node = node->next;
	}
	return (0);
}