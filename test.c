#include "push_swap.h"
#include <stdio.h>

void	print_function(t_list *ptr)
{
	while (ptr)
	{
		printf("%d\n", ptr->value);
		ptr = ptr->next;
	}
}
//swap_nodes_only(&ptr);
//sa et sb : swap_nodes(&ptr, 'b'); ou 'a';
//ra et rb : decale d'une position vers le haut, le 1er devient dernier
int main(void)
{
	t_list	*ptr;
	ptr = NULL;
	
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	
	int n1 = 1;
	int	n2 = 2;
	int	n3 = 3;
	int	n4 = 4;
	
	node1 = ft_lstnew(n1);
	node2 = ft_lstnew(n2);
	node3 = ft_lstnew(n3);
	node4 = ft_lstnew(n4);
	
	ft_lstadd_front(&ptr, node4);
	ft_lstadd_front(&ptr, node3);
	ft_lstadd_front(&ptr, node2);
	ft_lstadd_front(&ptr, node1);

	print_function(ptr);
	//swap_nodes_only(&ptr);
	//swap_nodes(&ptr, 'b'); ou 'a';
	//rotate_only(&ptr) OU rotate_only(&stack_a);
	//rotate(&ptr, 'b') OU rotate_only(&stack_a, 'b');
	print_function(ptr);
	//free();
	return (0);
}
//ss : swap_a_and_b
//pa, pb : push_to_a && push_to_b
// rr : rotate_a_and_b
int main(void)
{
	t_list *stack_a;
	t_list *stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	
	t_list	*a1;
	t_list	*a2;
	t_list	*a3;
	t_list	*a4;

	t_list	*b1;
	t_list	*b2;
	t_list	*b3;
	t_list	*b4;
	
	int na1 = 1;
	int	na2 = 2;
	int	na3 = 3;
	int	na4 = 4;
	
	int nb1 = 1;
	int	nb2 = 2;
	int	nb3 = 3;
	int	nb4 = 4;
	
	a1 = ft_lstnew(na1);
	a2 = ft_lstnew(na2);
	a3 = ft_lstnew(na3);
	a4 = ft_lstnew(na4);
	
	b1 = ft_lstnew(nb1);
	b2 = ft_lstnew(nb2);
	b3 = ft_lstnew(nb3);
	b4 = ft_lstnew(nb4);
	
	ft_lstadd_front(&stack_a, a4);
	ft_lstadd_front(&stack_a, a3);
	ft_lstadd_front(&stack_a, a2);
	ft_lstadd_front(&stack_a, a1);
	
	ft_lstadd_front(&stack_b, b4);
	ft_lstadd_front(&stack_b, b3);
	ft_lstadd_front(&stack_b, b2);
	ft_lstadd_front(&stack_b, b1);

	print_function(stack_a);
	printf("\n");
	print_function(stack_b);
	printf("\n");
	//swap_a_and_b(&stack_a, &stack_b);
	//push_to_b(&stack_a, &stack_b);
	//push_to_a(&stack_a, &stack_b);
	//rotate_a_and_b(&stack_a, &stack_b);
	printf("\n");
	print_function(stack_a);
	printf("\n");
	print_function(stack_b);
	//free();
	return (0);
}
