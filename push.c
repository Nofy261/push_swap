/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:12:44 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/16 15:36:54 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list *head;

	head = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, head);
	
	write(1, "pa\n", 3);
	
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, head);
	write (1, "pb\n", 3);
}
