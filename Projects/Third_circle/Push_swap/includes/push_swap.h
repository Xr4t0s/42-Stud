#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int			    value;
	int				cost;
	struct s_stack	*next;	
}	t_stack;

void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content);
int		ft_lstsize(t_stack *lst);
void	ft_lstiter(t_stack *lst, int (*f)(const char *, ...));

// Instructions 

int swap_a_or_b(t_stack **stack);
int swap_a_and_b(t_stack **stack_a, t_stack **stack_b);
int push_to(t_stack **stack_from, t_stack **stack_to);
int rotate_a_or_b(t_stack **stack);
int rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);
int reverse_rotate_a_or_b(t_stack **stack);
int reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);

// Free
void	ft_lstfree(t_stack *lst);
void	free_arg(char **tab);

char **sanitizeEntry(char **av);


#endif