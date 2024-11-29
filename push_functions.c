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