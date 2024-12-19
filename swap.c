/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:13:35 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/19 13:27:22 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nodes(t_list **stack, char x)
{
	t_list	*tmp_node;

	if (ft_lstsize(*stack) < 2)
		return ;
	tmp_node = (*stack)->next;
	(*stack)->next = tmp_node->next;
	tmp_node->next = *stack;
	*stack = tmp_node;
	if (x == 'a')
		write(1, "sa\n", 3);
	else if (x == 'b')
		write(1, "sb\n", 3);
}

void	swap_a_and_b(t_list **stack_a, t_list **stack_b)
{
	swap_nodes(stack_a, 'c');
	swap_nodes(stack_b, 'c');
	write(1, "ss\n", 3);
}
