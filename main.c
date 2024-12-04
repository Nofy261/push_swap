/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:11:31 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/04 15:40:54 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"
 #include <stdlib.h>
 #include <stdio.h>
 

//reverse_rotate_only ✅️ a revoir comprehension 

void	print_function(t_list *ptr)
{
	while (ptr)
	{
		printf("%d\n", ptr->value);
		ptr = ptr->next;
	}
}

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
	reverse_rotate_a_and_b(&stack_a, &stack_b);
	printf("\n");
	print_function(stack_a);
	printf("\n");
	print_function(stack_b);
	//free();
	return (0);
}

