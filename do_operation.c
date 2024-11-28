#include "push_swap.h"

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, tmp);
	write(1, "pa\n", 3);

}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;

	ft_lstadd_front(stack_b, tmp);
	write (1, "pb\n", 3);
}

int    swap_a(t_list **stack)
{
    // Utilisation de la fonction ft_swap
    if (ft_swap_node(stack) == -1)
        return (-1);

    // Afficher l'opération "sa" pour le checker de push_swap
    write(1, "sa\n", 3);
    return (0);
}

int    ft_swap_node(t_list **stack)
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