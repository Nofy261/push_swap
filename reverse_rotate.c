/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:13:13 by nolecler          #+#    #+#             */
/*   Updated: 2024/11/30 12:31:38 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack, char x)
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

void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_only(stack_a);
	reverse_rotate_only(stack_b);
	write (1, "rrr\n", 4);
}




