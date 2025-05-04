/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 07:12:26 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/04 17:55:38 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    dequote(t_arg **arg)
{
    int    start;
    int    end;
    char    *str;
    t_arg    *tmp;
    
    tmp = *arg;
    while((tmp))
    {
        start = 0;
        end = ft_strlen(tmp->value);
        if (tmp->type == T_DQUOTE || tmp->type == T_QUOTE)
        {
            tmp->value = ft_substr(tmp->value, 1, (end - 2));
        }
        else if (tmp->type == T_WORD)
        {
            while (tmp->value[start] && tmp->value[start] != '\"' && tmp->value[start] != '\'')
                start++;
            if (start == end)
            {
                tmp = tmp->next;
                continue ;
            }
            else
            {
                while (tmp->value[end] != '\"' && tmp->value[end] != '\'')
                    end--;
            }
            str = ft_substr(tmp->value, 0, start);
            tmp->value = ft_strjoin(str, ft_substr(tmp->value, (start + 1), (end - start - 1)));
            free(str);
        }
        tmp = tmp->next;
    }
}
