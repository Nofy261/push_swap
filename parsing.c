/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:35:20 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/05 13:56:31 by nolecler         ###   ########.fr       */
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
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

//boucle qui parcourt argc
//fonction qui stocke argv
//split sur les espaces
//creer un tableau de tableau et stocke la valeur de retour de ft_split
int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	char **tableau;
	t_list *list_a;
	t_list *list_b;

	list_a = NULL;
	list_b = NULL;
	if (verif_argc(argc) == 1 || check_sign(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	while (i < argv)
	{
		tableau = ft_split(argv[i], ' ');
		
	}
}
// est ce qu on gere si on met une tabulation entre les chiffres et non un espace??
void	check_errors(char *str) //cas ++++++667778764
{	
	if (ft_atoi(str) == 0) // si atoi retourne 0; //a voir car si +7ab56 : atoi retourne 7;
	{
		write (1, "Error\n", 6);
		return ; // on arrete le programme;
	}
	//else ?? necessaire ou pas??
}



//parcourir tout le tab de tab
// dans la boucle on appelle la fonction check_errors puis on appel l atoi normal
//stocker la valeur de retour de atoi dans value et value sera un int
//mettre value dans un node
//ajouter ce node a la liste a
// ajoute le node a la fin de la liste a

void	parse_arguments(t_list **stack_a, char **big_argv)
{
	int	i;
	int	j;
	int	value;
	t_list *newnode;
	//t_list *stack_a = NULL; necessaire ou pas?

	value = 0;
	i = 0;
	j = 1;
	while (big_argv[j] != '\0')
	{
		i = 0;
		while (big_argv[j][i])
		{
			check_errors(big_argv[j]);
			//rajouter la fonction check_sign ici ??
			value = ft_atoi(big_argv[j]);
			newnode = ft_lstnew(value); //creer un noeud
			ft_lstadd_back(&stack_a, newnode); //place le noeud dans la liste
			//i++;?? qu'est ce qu'on incremente ici?
		}
		j++;
	}
}
//gerer +99 99 = meme chose et +99  -99 == n'est pas la meme valeur 
// gerer int min et int max

//verifier si le meme arg ne revient pas 2fois
//faire une boucle qui parcourt la liste jusqu a la fin
// N’oubliez pas que vous devez afficher 'Error' sur la sortie d’erreur (stderr, fd 2) !

int	check_double(t_list **stack_a)
{
	t_list *current = stack_a;
	while (current)
	{
		t_list *next_list = current->next;
		while(next_list)
		{
			if (current->value == next_list->value)
			{
				printf("error");
				return (-1);
			}
			next_list = next_list->next; 
		}
		current = current->next;
	}
}