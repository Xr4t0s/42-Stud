#include "push_swap.h"

void	ft_lstfree(t_stack *lst)
{
	t_stack *tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void free_arg(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}
