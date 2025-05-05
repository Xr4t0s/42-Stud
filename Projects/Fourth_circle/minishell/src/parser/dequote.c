/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 07:12:26 by engiacom          #+#    #+#             */
/*   Updated: 2025/05/05 08:19:20 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void    dequote(t_arg **arg)
// {
//     int    start;
//     int    end;
//     char    *str;
//     t_arg    *tmp;
// 	char	*str_end;
// 	int		q;
// 	int		dq;
    
//     tmp = *arg;
// 	q = 0;
// 	dq = 0;
//     while((tmp))
//     {
//         start = 0;
//         if (tmp->type == T_DQUOTE || tmp->type == T_QUOTE)
//         {
//             tmp->value = ft_substr(tmp->value, 1, (end - 2));
//         }
//         else if (tmp->type == T_WORD)
//         {
// 			while ()
// 			{
// 				while (tmp->value[start] && tmp->value[start] != '\"' && tmp->value[start] != '\'')
// 					start++;
// 				if (tmp->value[start] == '\"')
// 					dq = 1;
// 				else if (tmp->value[start] == '\'')
// 					q = 1;
// 				if (start == (int)ft_strlen(tmp->value))
// 				{
// 					tmp = tmp->next;
// 					break ;
// 				}
// 				else
// 				{
// 					end = start + 1;
// 					if (q == 1)
// 					{
// 						while (tmp->value[end] != '\'')
// 							end++;
// 					}
// 					else if (dq == 1)
// 					{
// 						while (tmp->value[end] != '\"')
// 							end++;
// 					}
// 				}
// 				str = ft_substr(tmp->value, 0, start);
// 				str_end = ft_substr(tmp->value, end + 1, (ft_strlen(tmp->value) - end));
// 				tmp->value = ft_strjoin(str, ft_substr(tmp->value, (start + 1), (end - start - 1)));
// 				tmp->value = ft_strjoin(tmp->value, str_end);
// 				free(str);
// 				start = end;
// 			}
//         }
//         tmp = tmp->next;
//     }
// }
char	*ft_unquote(char *str, int start, int end)
{
	char	*start_s;
	char	*mid_s;
	char	*end_s;
	char	*ret;

    if (start == 0 && end == ft_strlen(str) - 1)
    {
        ret = ft_substr(str, 1, ft_strlen(str) - 2);
        return (ret);
    }
    if (start == 0)
        start_s = ft_calloc(8, 1);
	else
    	start_s = ft_substr(str, 0, start);
	mid_s = ft_substr(str, start + 1, (end - start - 1));
	end_s = ft_substr(str, end + 1, ft_strlen(str) - end);
	ret = ft_strjoin(start_s, mid_s);
	ret = ft_strjoin(ret, end_s);
	return (free(start_s), free(mid_s), free(end_s), ret);
}

char    *dequote(char *tmp, int start)
{
	int	q;
	int	dq;
	int	end;
	char	*str;

	q = 0;
	dq = 0;
	end = 0;
	str = tmp;
	while (str[start] && str[start] != '\"' && str[start] != '\'')
		start++;
	if (str[start] == '\"' && q == 0)
		dq = 1;
	else if (str[start] == '\'' && dq == 0)
		q = 1;
	if (q == 1)
	{
		if (!str[start + 1])
			return (tmp);
		end = start + 1;
		while (str[end] != '\'')
			end++;
	}
	else if (dq == 1)
	{
		if (!str[start + 1])
			return (tmp);
		end = start + 1;
		while (str[end] != '\"')
			end++;
	}
	if (!str[start])
		return (tmp);
    tmp = ft_unquote(tmp, start, end);
    start = end - 2;
    return (dequote(tmp, start));
}

void slash(t_arg **arg)
{
    t_arg   *tmp;

    tmp = *arg;
    while(tmp)
    {
        tmp->value = dequote(tmp->value, 0);
		tmp = tmp->next;
    }
}

