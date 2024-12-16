/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:45:39 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/16 17:17:07 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *find_min(t_list *stack_a)
{
    t_list *min = stack_a; //les deux pointent vers un meme maillon

    while (min->next && min->rank != -1)
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
    int            count;
    int            len;

    count = 0;
    len = ft_lstsize(*stack_a);
    while (count < len)
    {
		find_min(*stack_a)->rank = count;
        count++;
    }
}

// a etudier !important

static void	ft_normalisation(t_list *a)
{
	t_list	*save;
	t_list	*current;
	int		count;

	count = 0;
	save = a;
	current = a;
	while (save)
	{
		count = 0;
		while (current)
		{
			if (save->value > current->value)
				count++;
			current = current->next;
		}
		save->rank = count;
		save = save->next;
		current = a;
	}
}

void	sort_three(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
    ft_normalisation(*stack_a);
	if (current->rank == 1 && current->next->rank == 0)
		swap_nodes(stack_a, 'a');
	else if (current->rank == 2 && current->next->rank == 1)
	{
		swap_nodes(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
	else if (current->rank == 2 && current->next->rank == 0)
		rotate(stack_a, 'a');
	else if (current->rank == 0 && current->next->rank == 2)
	{
		swap_nodes(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (current->rank == 1 && current->next->rank == 2)
		reverse_rotate(stack_a, 'a');
}

void    sort_five(t_list **stack_a, t_list **stack_b)
{
    int i;

    i = 5;
    if (is_sorted_or_not(*stack_a))
        return ;
    while (i > 3)
    {
        if ((*stack_a)->rank == 0 || (*stack_a)->rank == 1)//on met dans b les 2 plus petits
        {
            push(stack_b, stack_a, 'b');
            i--;
        }
        else
           rotate(stack_a, 'a');
    }
    sort_three(stack_a);
    if (*stack_b && (*stack_b)->next
        && (*stack_b)->rank < (*stack_b)->next->rank)//le plus petit doit etre place en 2eme dans b sinon on swao avant d'envoyer
    {
        swap_nodes(stack_b, 'b');
    }
    push(stack_a, stack_b, 'a');
    push(stack_a, stack_b, 'a');
}

