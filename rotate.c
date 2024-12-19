/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:13:24 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/19 13:24:50 by nolecler         ###   ########.fr       */
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

void	rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 'c');
	rotate(stack_b, 'c');
	write(1, "rr\n", 3);
}
