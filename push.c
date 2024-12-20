/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:12:44 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/17 16:11:32 by nolecler         ###   ########.fr       */
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
