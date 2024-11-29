#include "push_swap.h"

// ra ❌
// rb ❌
// rr ❌
// rra ❌
// rrb ❌
// rrr ❌

//ra : decale d'une position vers le haut tous les elemnt de a 
//     le premier devient le dernier




void	ra(t_list **stack_a)
{
	t_list	*tmp;

	ft_lstlast(stack_a)->next = (*stack_a);
	tmp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	tmp = (*stack_a);	
	write (1, "ra\n", 3);
}
