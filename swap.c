/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:13:35 by nolecler          #+#    #+#             */
/*   Updated: 2024/11/30 09:48:30 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    swap_nodes(t_list **stack, char x)
{
    t_list    *tmp_node;

    if (ft_lstsize(*stack) < 2)
        return (-1);
    // Swapper les deux premiers éléments
    tmp_node = (*stack)->next;
    (*stack)->next = tmp_node->next;
    tmp_node->next = *stack;
    *stack = tmp_node;
    if (x == 'a')
        write(1, "sa\n", 3);
    else if (x == 'b')
        write(1, "sb\n", 3);
    return (0);
}

int    swap_nodes_only(t_list **stack)
{
    t_list    *tmp_node;

    if (ft_lstsize(*stack) < 2)
        return (-1);
    // Swapper les deux premiers éléments
    tmp_node = (*stack)->next;
    (*stack)->next = tmp_node->next;
    tmp_node->next = *stack;
    *stack = tmp_node;
    return (0);
}

void    swap_a_and_b(t_list **stack_a, t_list **stack_b)
{
    swap_nodes_only(stack_a);
    swap_nodes_only(stack_b);
    write(1, "ss\n", 3);
}
