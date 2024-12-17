/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:13:24 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/17 12:44:16 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	rotate(t_list **stack, char x)
{
	t_list	*tmp;
	t_list	*current;

	if (ft_lstsize(*stack) <= 1)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	current = *stack;
	while (current->next)
	{
		current = current->next;
	}
	tmp->next = NULL;
	current->next = tmp;
	if (x == 'a')
		write (1, "ra\n", 3);
	else if (x == 'b')
		write (1, "rb\n", 3);
}

void	rotate_only(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	tmp = *stack;
	*stack = (*stack)->next;
	current = *stack;
	while (current->next)
	{
		current = current->next;
	}
	tmp->next = NULL;
	current->next = tmp;
}

void	rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	rotate_only(stack_a);
	rotate_only(stack_b);
	write(1, "rr\n", 3);
}

