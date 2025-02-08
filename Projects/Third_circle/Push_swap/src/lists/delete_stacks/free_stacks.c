/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:59:01 by nitadros          #+#    #+#             */
/*   Updated: 2025/01/31 00:59:01 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstfree(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst || !*lst)
		return;
	while (*lst)
	{
		tmp = (*lst)->next; // Sauvegarde l'adresse du prochain élément avant free()
		free(*lst);         // Libération de l'élément courant
		*lst = tmp;         // Passe à l'élément suivant
	}
	*lst = NULL; // 🔥 Corrige l'accès à une mémoire libérée
}

void	free_arg(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
