/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:12:44 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/14 18:50:39 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, tmp);
	(*stack_a)->next = NULL;//rajout 
	//*stack_a = tmp; //non
	//tmp->next = NULL; //non
	//tmp->next = *stack_a; //non
	//tmp->next = *stack_b;
	
	
	write(1, "pa\n", 3);
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, tmp);
	(*stack_b)->next = NULL;//rajout 
	write (1, "pb\n", 3);
}
