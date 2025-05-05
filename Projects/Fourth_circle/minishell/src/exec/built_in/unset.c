/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:01:25 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/05 02:37:55 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	*ft_unquote(char *str, int start, int end)
// {
// 	char	*start_s;
// 	char	*mid_s;
// 	char	*end_s;
// 	char	*ret;

// 	start_s = ft_substr(str, 0, start - 1);
// 	mid_s = ft_substr(str, start + 1, end - 1);
// 	end_s = ft_substr(str, end + 1, ft_strlen(str));
// 	ret = ft_strjoin(start, mid);
// 	ret = ft_strjoin(ret, end);
// 	return (free(start_s), free(mid_s), free(end_s), ret);
// }

// void slash(t_arg **arg)
// {
//     t_arg   *tmp;

//     tmp = *arg;
//     while(tmp)
//     {
//         tmp->value = dequote(tmp->value, 0);
// 		tmp = tmp->next;
//     }
// }
