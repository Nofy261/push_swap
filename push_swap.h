/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:12:35 by nolecler          #+#    #+#             */
/*   Updated: 2024/11/30 08:12:38 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;


/*  Utils */
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstsize(t_list *lst);

/* Push */
void	push_to_a(t_list **stack_a, t_list **stack_b);
void	push_to_b(t_list **stack_a, t_list **stack_b);

/* Swap */
int    swap_nodes(t_list **stack, char x);
int    swap_nodes_only(t_list **stack);
void    swap_a_and_b(t_list **stack_a, t_list **stack_b);

/* Rotate */
void	rotate(t_list **stack, char x);
void	rotate_only(t_list **stack);
void	rotate_a_and_b(t_list **stack_a, t_list **stack_b);

/* Reverse and Rotate */
void	reverse_rotate(t_list **stack, char x);
void	reverse_rotate_only(t_list **stack);
void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b);


#endif