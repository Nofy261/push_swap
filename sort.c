/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:45:39 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/14 16:59:51 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list    *find_max(t_list *stack_a)
{
	t_list *max = stack_a;
	
	while(stack_a)
	{
		if(stack_a->value > max->value)
			max = stack_a;
		stack_a = stack_a->next;
	}
	return (max);
}

static t_list    *find_min(t_list *stack_a)
{
	t_list *min = stack_a; //les deux pointent vers un meme maillon
	
	while (min->rank != -1)
		min = min->next;
	
	while(stack_a)
	{
		if(stack_a->value < min->value && stack_a->rank == -1)
			min = stack_a;
		stack_a = stack_a->next;
	}
	return (min);
}

void    set_rank(t_list **stack_a)
{
    int            i;
    int            len;

    i = 0;
    len = ft_lstsize(*stack_a);
    while (i < len)
    {
		find_min(*stack_a)->rank = i;
        i++;
    }
}

void	sort_three(t_list **stack_a)
{
	t_list	*min;
	t_list	*max;

	min = find_min(*stack_a);
	max = find_max(*stack_a);
	if (ft_lstsize(*stack_a) == 3)
	{
		if ((*stack_a)->next->value == min->value && (*stack_a)->next->next->value == max->value)
			swap_nodes(stack_a, 'a');
		else if ((*stack_a)->value == max->value && (*stack_a)->next->next->value == min->value)
		{
			swap_nodes(stack_a, 'a');
			reverse_rotate(stack_a, 'a');
		}
		else if ((*stack_a)->value == max->value && (*stack_a)->next->value == min->value)
			rotate(stack_a, 'a');
		else if ((*stack_a)->value == min->value && (*stack_a)->next->value == max->value)
		{
			swap_nodes(stack_a, 'a');
			rotate(stack_a, 'a');
		}
		else if ((*stack_a)->next->value == max->value && (*stack_a)->next->next->value == min->value)
			reverse_rotate(stack_a, 'a');
	}	
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	count_b;
	t_list *min;
	
	count_b = 0;
	while(count_b < 2)
	{
		min = find_min(*stack_a);
		while (min != *stack_a) // tant que min n'est pas au debut de la liste
		{
			rotate(stack_a, 'a');
		}
		push_to_b(stack_a, stack_b);
		count_b++;
	}
	sort_three(stack_a);
	push_to_a(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
}

