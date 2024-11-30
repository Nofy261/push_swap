/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:13:24 by nolecler          #+#    #+#             */
/*   Updated: 2024/11/30 08:13:29 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	rotate(t_list **stack, char x)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) <= 1)
		return ;
	tmp = (*stack)->next;
	ft_lstlast(stack)->next = (*stack);
	(*stack)->next = NULL;
	(*stack) = tmp;
	if (x == 'a')
		write (1, "ra\n", 3);
	else if (x == 'b')
		write (1, "rb\n", 3);
}

void	rotate_only(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) <= 1)
		return ;
	tmp = (*stack)->next;
	ft_lstlast(stack)->next = (*stack);
	(*stack)->next = NULL;
	(*stack) = tmp;
}
void	rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	rotate_only(stack_a);
	rotate_only(stack_b);
	write(1, "rr\n", 3);
}

