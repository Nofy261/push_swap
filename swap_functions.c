#include "push_swap.h"


// pa ✅
// pb ✅
// sa ✅
// sb ✅
// ss ✅
// ra ❌
// rb ❌
// rr ❌
// rra ❌
// rrb ❌
// rrr ❌

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

int    swap_a(t_list **stack)
{
    // Utilisation de la fonction ft_swap
    if (ft_swap_node(stack) == -1)
        return (-1);

    // Afficher l'opération "sa" pour le checker de push_swap
    write(1, "sa\n", 3);
    return (0);
}
int swap_b(t_list **stack)
{
    if (ft_swap_node(stack) == -1)
        return (-1);
    write(1, "sb\n", 3);
    return (0);
}
void    swap_a_and_b(t_list **stack_a, t_list **stack_b)
{
    swap_a(&stack_a);
    swap_b(&stack_b);
}
