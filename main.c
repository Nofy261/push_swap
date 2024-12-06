/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:35:20 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/06 10:22:36 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// gerer int min et int max ❌
// est ce qu on gere si on met une tabulation entre les chiffres et non un espace??❌ 


//boucle qui parcourt argc ✅
//fonction qui stocke argv  ❌
//split sur les espaces ✅
//creer un tableau de tableau et stocke la valeur de retour de ft_split ❌


int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	char **cut_argv;
	t_list *list_a;
	t_list *list_b;

	list_a = NULL;
	list_b = NULL;
	cut_argv = NULL;
	if (verif_argc(argc) == 1 || check_sign(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		
		cut_argv = ft_split(argv[i], ' ');
		
	}
}


