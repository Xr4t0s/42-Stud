

#include "minishell.h"

t_redir	*ft_lstnew_r(t_redir_type type, char *target)
{
	t_redir	*new;

	new = malloc(sizeof(t_redir));
	if (new == NULL)
		return (NULL);
	new->type = type;
	new->target = ft_strdup(target);
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_r(t_redir **arg, t_redir *new)
{
	t_redir	*tmp;

	if (*arg == NULL)
		*arg = new;
	else
	{
		tmp = *arg;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
