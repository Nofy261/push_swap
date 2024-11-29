#include "push_swap.h"

// ra ✅
// rb ✅
// rr ✅
// rra ✅
// rrb ✅
// rrr ✅

//ra / rb : decale d'une position vers le haut tous les elemnt de a ou b
//     le premier devient le dernier




void	rotate_a(t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a)->next;
	ft_lstlast(stack_a)->next = (*stack_a);
	(*stack_a)->next = NULL;
	(*stack_a) = tmp;	
	write (1, "ra\n", 3);
}
void	rotate_b(t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_b)->next;
	ft_lstlast(stack_b)->next = (*stack_b);
	(*stack_b)->next = NULL;
	(*stack_b) = tmp;	
	write (1, "rb\n", 3);
}
void	rotate_a_and_b(t_list **stack_a, t_list stack_b)
{
	rotate_a(&stack_a);
	rotate_b(&stack_b);
	write(1, "rr\n", 3);
}