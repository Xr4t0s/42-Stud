#include "push_swap.h"

t_stack *ft_lstnew(int content)
{
    t_stack *new;

    new = (t_stack *)calloc(sizeof(t_stack), 1);
    if (!new)
        return (NULL);
    new->value = content;
    new->next = NULL;
    return (new);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*bckp;

	if (!lst)
		return (NULL);
	bckp = lst;
	while (bckp->next != NULL)
		bckp = bckp->next;
	return (bckp);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
