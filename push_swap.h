/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:12:35 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/10 13:05:12 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;


/*  Utils */
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int value);

/*  Utils2 */

int		ft_atoi(char *str);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char	*s, int fd);
int	ft_isdigit(int c);

/* Push */
void	push_to_a(t_list **stack_a, t_list **stack_b);
void	push_to_b(t_list **stack_a, t_list **stack_b);

/* Swap */
void    swap_nodes(t_list **stack, char x);
void    swap_nodes_only(t_list **stack);
void    swap_a_and_b(t_list **stack_a, t_list **stack_b);

/* Rotate */
void	rotate(t_list **stack, char x);
void	rotate_only(t_list **stack);
void	rotate_a_and_b(t_list **stack_a, t_list **stack_b);

/* Reverse and Rotate */
void	reverse_rotate(t_list **stack, char x);
void	reverse_rotate_only(t_list **stack);
void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b);

/* Parsing */
int verif_argc(int argc);
int	check_sign(char **argv);
void	check_errors(char *str);
void	parse_arguments(t_list **stack_a, char **big_argv);
int	check_double(t_list **stack_a);






#endif