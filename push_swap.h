/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:12:35 by nolecler          #+#    #+#             */
/*   Updated: 2024/12/18 11:09:01 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				rank;
	struct s_list	*next;
}					t_list;

void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int value);

int		ft_atoi(char *str, t_list **stack_a, char **cut_argv);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char	*s, int fd);
int		ft_isdigit(int c);

void	push(t_list **stack_dst, t_list **stack_src, char c);

void	swap_nodes(t_list **stack, char x);
void	swap_nodes_only(t_list **stack);
void	swap_a_and_b(t_list **stack_a, t_list **stack_b);

void	rotate(t_list **stack, char x);
void	rotate_only(t_list **stack);
void	rotate_a_and_b(t_list **stack_a, t_list **stack_b);

void	reverse_rotate(t_list **stack, char x);
void	reverse_rotate_only(t_list **stack);
void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b);

int		check_sign(char **argv);
void	parse_arguments(t_list **stack_a, char **big_argv);
int		check_double(t_list *stack_a, char **cut_argv);

void	sort_three(t_list **stack_a);
void	sort_five(t_list **stack_a, t_list **stack_b);

void	check_sort(t_list **stack_a, t_list **stack_b);
int		is_sorted_or_not(t_list *stack_a);
void	sort_two(t_list **stack_a);
void	radix_sort(t_list **stack_a, t_list **stack_b);

void	normalisation(t_list *stack_a);
void	print_error(char **cut_argv, t_list **stack_a);

void	*free_all(char **str);
void	free_list(t_list *stack_a);
void	free_end(t_list **stack_a, t_list **stack_b, char **cut_argv);

#endif