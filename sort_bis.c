/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:51:04 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/17 14:39:20 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_or_not(t_list *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort_two(t_list **stack_a)
{
	int	i;

	i = ft_lstsize(*stack_a);
	if (i == 2)
		swap_nodes(stack_a, 'a');
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	len;
	int	i;

	i = 0;
	while (is_sorted_or_not(*stack_a) == 0)
	{
		len = ft_lstsize(*stack_a);
		while (len-- && is_sorted_or_not((*stack_a)) == 0)
		{
			if ((((*stack_a)->rank >> i) & 1))
				rotate(stack_a, 'a');
			else
				push(stack_b, stack_a, 'b');
		}
		len = ft_lstsize(*stack_b);
		while (len--)
		{
			push(stack_a, stack_b, 'a');
		}
		i++;
	}
}