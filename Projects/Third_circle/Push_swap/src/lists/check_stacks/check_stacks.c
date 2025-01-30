#include "push_swap.h"

void	ft_lstiter(t_stack *lst, int (*f)(const char *, ...))
{
	while (lst)
	{
        if (lst->next == NULL)
            f("%d\n", lst->value);
        else
            f("%d, ", lst->value);
		lst = lst->next;
	}
}

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*bckp;

	i = 0;
	if (!lst)
		return (0);
	bckp = lst;
	while (bckp->next != NULL)
	{
		bckp = bckp->next;
		i++;
	}
	i++;
	return (i);
}

int isSorted(t_stack *lst)
{
	t_stack *bckp;

	if (!lst)
		return (0);
	bckp = lst;
	while (bckp->next != NULL)
	{
		if (bckp->value > bckp->next->value)
			return (0);
		bckp = bckp->next;
	}
	return (1);
}