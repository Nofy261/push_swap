/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:12:44 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/17 12:35:53 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_dst, t_list **stack_src, char c)
{
	t_list	*head;

	head = *stack_src;
	*stack_src = (*stack_src)->next;
	ft_lstadd_front(stack_dst, head);
	if (c == 'a')
		write (1, "pa\n", 3);
	else if (c == 'b')
		write (1, "pb\n", 3);
}

// void	push_to_a(t_list **stack_src, t_list **stack_dst)
// {
// 	t_list *head;

// 	head = *stack_dst;
// 	*stack_dst = (*stack_dst)->next;
// 	ft_lstadd_front(stack_src, head);
	
// 	write(1, "pa\n", 3);
	
// }

// void	push_to_b(t_list **stack_dst, t_list **stack_src)
// {
// 	t_list	*head;
	
// 	head = *stack_src;
// 	*stack_src = (*stack_src)->next;
// 	ft_lstadd_front(stack_dst, head);
// 	write (1, "pb\n", 3);
// }
