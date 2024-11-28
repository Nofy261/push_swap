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

void	swap_a(t_list **stack_a)
{
	//intervertit les 2 premiers elements au sommet de a
	t_list *tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_swap(*tmp, *stack_a);//echange les deux nodes
}
