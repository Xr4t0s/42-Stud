/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:32:01 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/30 16:42:28 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    check_quote(char *line)
{
    int    q;
    int    dq;
    int    i;

    q = 0;
    dq = 0;
    i = 0;
    while (line[i])
    {
        if (q == 0 && dq == 0 && line[i] == '\'')
            q = 1;
        else if (q == 0 && dq == 0 && line[i] == '\"')
            dq = 1;
        else if (line[i] == '\'' && q == 1)
            q = 0;
        else if (line[i] == '\"' && dq == 1)
            dq = 0;
        i++;
    }
    return (q + dq);
}

int	check_pipe(t_arg *arg)
{
	int	p;

	p = 0;
	while (arg)
	{
		if (arg->type == T_PIPE)
			p = 1;
		if (arg->type == T_WORD && p == 1)
			p = 0;
		arg = arg->next;
	}
	return (p);
}