#include "push_swap.h"

// rra ✅
// rrb ✅
// rrr ✅

//rra : Décale d’une position vers le bas tous les élements de a
	//  Le dernier élément devient le premier.
//rrb : Décale d’une position vers le bas tous les élements de b
	//  Le dernier élément devient le premier.
//rrr : faire rra et rrb en meme temps.

//le dernier devient le premier

//*head->node1->node2->node3->null
// *head->node3->node1->node2->null


void	reverse_rotate_a(t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a);
	ft_lstlast(stack_a)->next = (*stack_a);
	(*stack_a) = ft_lstlast(stack_a);
	(*stack_a)->next = tmp;
	tmp->next=NULL;
	write(1, "rra\n", 4);
}
void	reverse_rotate_b(t_list **stack_b)
{
	t_list	*tmp;

	tmp = (*stack_b);
	ft_lstlast(stack_b)->next = (*stack_b);
	(*stack_b) = ft_lstlast(stack_b);
	(*stack_b)->next = tmp;
	tmp->next=NULL;
	write (1, "rrb\n", 4);
}

void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	write (1, "rrr\n", 4);
}




