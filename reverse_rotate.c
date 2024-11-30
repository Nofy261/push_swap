/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:13:13 by nolecler          #+#    #+#             */
/*   Updated: 2024/11/30 08:13:16 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	reverse_rotate(t_list **stack, char x)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) <= 1)
		return ;
	tmp = (*stack);
	ft_lstlast(stack)->next = (*stack);
	(*stack) = ft_lstlast(stack);
	(*stack)->next = tmp;
	tmp->next=NULL;
	if (x == 'a')
		write(1, "rra\n", 4);
	else if (x == 'b')
		write(1, "rrb\n", 4);
}
void   reverse_rotate_only(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) <= 1)
		return ;
	tmp = (*stack);
	ft_lstlast(stack)->next = (*stack);
	(*stack) = ft_lstlast(stack);
	(*stack)->next = tmp;
	tmp->next=NULL;
}

void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_only(stack_a);
	reverse_rotate_only(stack_b);
	write (1, "rrr\n", 4);
}




