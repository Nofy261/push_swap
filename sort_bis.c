/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:51:04 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/14 16:46:59 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//#include <stdio.h> // A enlever avant push

int	is_sorted_or_not(t_list *stack_a)
{
	while (stack_a && stack_a->next != NULL)
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

void	sort_two(t_list **stack_a)
{
	int	i;
	
	i = ft_lstsize(*stack_a);
	if (i == 2)
		swap_nodes(stack_a, 'a');
}
 #include <stdio.h>
 
// void    radix_sort(t_list **stack_a, t_list **stack_b)
// {
// 	//rank indique la position de chaque nombre, rank[0] correspond au plus petit chiffre
//     int            i;//index pour les bits de rank Ex: rank0 = 8 = 1000 en binaire et i[0] sera au 0 le plus a droite de 1000, et i[3] = 1
//     int            len;

//     i = 0;
//     while (is_sorted_or_not((*stack_a)) == 1)// tant que la stack_a n'est pas triee
//     {
//         len = ft_lstsize((*stack_a));
//         while (len-- && is_sorted_or_not((*stack_a)) == 1)
//         {
// 			// si bit = 1, la condition est vrai
//             if ((((*stack_a)->rank >> i) & 1))//c'est une operation qui donne 1 ou 0 et si l operation donne 1 cad si bit = 1 ,on rotate a sinon push_to_b
//             //ex:rank=2 et i=1(on verifie le 2em bit a droite); ((2 >> 1) & 1) = (0010 >> 1) & 1 = 1; car decalage d'un bit vers la droite de 0010 = 0001 et 0001 & 0001 = 1;
// 			    rotate(stack_a, 'a');
//             else
//                 push_to_b(stack_a, stack_b);//on met le 1 dans b
//         }
//         len = ft_lstsize((*stack_b));
//         while (len > 0)
// 		{
//             push_to_a(stack_a, stack_b);
// 			len--;
// 		}
// 		i++;
//     }
// }

void radix_sort(t_list **stack_a, t_list **stack_b)
{
    int            i;
    int            len;

    i = 0;
    while (is_sorted_or_not(*stack_a) == 1)
    {
        len = ft_lstsize(*stack_a);
        while (len-- && is_sorted_or_not((*stack_a)) == 1)
        {
            if ((((*stack_a)->rank >> i) & 1))
                rotate(stack_a, 'a');
            else
                push_to_b(stack_a, stack_b);
        }
        len = ft_lstsize(*stack_b);
        while (len--)
        {
            push_to_a(stack_a, stack_b);
        }
        i++;
    }
}
