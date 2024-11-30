/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:13:13 by nolecler          #+#    #+#             */
/*   Updated: 2024/11/30 12:27:30 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack, char x)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) <= 1)
		return ;
	tmp = (*stack);
	ft_lstlast(*stack)->next = (*stack);
	(*stack) = ft_lstlast(*stack);
	(*stack)->next = tmp;
	tmp->next=NULL;
	if (x == 'a')
		write(1, "rra\n", 4);
	else if (x == 'b')
		write(1, "rrb\n", 4);
}
void   reverse_rotate_only(t_list **stack)
{
	t_list *last;
	t_list *second_last;

	if (ft_lstsize(*stack) <= 1)
		return ;
	last = ft_lstlast(*stack);
	second_last = *stack;
	
	while (second_last->next != last)
	{
		second_last = second_last->next;	
	}

	second_last->next = NULL;
	
	last->next = *stack;
	*stack = last;
}

// void reverse_rotate_only(t_list **stack)
// {
//     t_list *last;
//     t_list *second_last;

//     // Si la pile a 0 ou 1 élément, on ne fait rien
//     if (*stack == NULL || (*stack)->next == NULL)
//         return;

//     second_last = *stack;
//     // Trouver l'avant-dernier élément
//     while (second_last->next->next != NULL)
//     {
//         second_last = second_last->next;
//     }

//     // `last` est maintenant le dernier élément
//     last = second_last->next;

//     // Déconnecter le dernier élément de la liste
//     second_last->next = NULL;

//     // Mettre le dernier élément au début de la liste
//     last->next = *stack;
//     *stack = last;
// }

void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_only(stack_a);
	reverse_rotate_only(stack_b);
	write (1, "rrr\n", 4);
}




