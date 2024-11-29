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

/* Push */
void	push_to_a(t_list **stack_a, t_list **stack_b);
void	push_to_b(t_list **stack_a, t_list **stack_b);

/* Swap */
int    ft_swap_node(t_list **stack);
int    swap_a(t_list **stack);

/* Rotate */
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_a_and_b(t_list **stack_a, t_list stack_b);

/* Reverse and Rotate */
 void	reverse_rotate_a(t_list **stack_a);
 void	reverse_rotate_b(t_list **stack_b);
 void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b);



#endif