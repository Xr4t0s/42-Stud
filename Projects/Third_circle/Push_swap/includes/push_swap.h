/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:02:08 by nitadros          #+#    #+#             */
/*   Updated: 2025/01/31 01:02:08 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost;
	int				cost_to_swap;
	int				is_min;
	int				is_mid;
	int				is_max;
	int				is_lowcost;
	struct s_stack	*target_node;
	struct s_stack	*next;	
}	t_stack;

void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content);
int		ft_lstsize(t_stack *lst);
void	ft_lstiter(t_stack *lst, int (*f)(const char *, ...));
int		is_sorted(t_stack *lst);
int		is_desc_sorted(t_stack *lst);

// Instructions 

int		swap_a_or_b(t_stack **stack, int a_or_b);
int		swap_a_and_b(t_stack **stack_a, t_stack **stack_b);
int		push_to(t_stack **stack_from, t_stack **stack_to, int a_or_b);
int		rotate_a_or_b(t_stack **stack, int a_or_b);
int		rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);
int		reverse_rotate_a_or_b(t_stack **stack, int a_or_b);
int		reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);
void	desc_sort(t_stack **stack_b);

// Checks
int		not_right_head(t_stack **stack_a);
t_stack	*is_upper_than_max(t_stack **stack_b);

// Initialization
void    index_stack(t_stack *stack);
void    establish_cost(t_stack *stack);
void	mark_limits(t_stack *stack);
void	mark_lowcost(t_stack **stack);
void	find_target_node(t_stack **stack_a, t_stack **stack_b);
void	establish_cost_to_swap(t_stack **stack);

// Algorithm
void	create_stack_a(t_stack **stack_a, char **args);
void	create_stack_b(t_stack **stack_a, t_stack **stack_b);
void	size_3(t_stack **stack);
void	sort_aglorithm(t_stack **stack_a);
void	algorithm(t_stack **stack_a);

// Free
void	ft_lstfree(t_stack **lst);
void	free_arg(char **tab);

// Sanitize
char	**sanitize_entry(char **av);
int		is_there_twins(char **args);

// Utils
char	*ft_strdup2(char *s);
long	*ft_atoi2(const char *str);
int		is_sanitized(char **args);
int		abs_v(int value);

#endif