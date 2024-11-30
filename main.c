/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:11:31 by nolecler          #+#    #+#             */
/*   Updated: 2024/11/30 09:25:50 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "push_swap.h"
 #include <stdlib.h>
 
//creer un main 
//compiler
//tester: sa sb pa pb ra rb rr rra rrb rrr

//creer une liste chaine pile a 
// y mettre des noeuds et tester ra etc...
//test avec swap_nodes_only : swap les 2premiers elements


t_list	*ft_lstnew(int value)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->value = value;
	newnode->next = NULL;
	return (newnode);
}

#include <stdio.h>

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

	printf("node1 %d\n", ptr->value);
	printf("node2 %d\n", ptr->next->value);
	printf("node3 %d\n", ptr->next->next->value);
	printf("node4 %d\n", ptr->next->next->next->value);

	swap_nodes_only(&ptr);
	
	printf("resultat apres appel de la fonction\n");

	printf("node1 %d\n", ptr->value);
	printf("node2 %d\n", ptr->next->value);
	printf("node3 %d\n", ptr->next->next->value);
	printf("node4 %d\n", ptr->next->next->next->value);


	return (0);
}

