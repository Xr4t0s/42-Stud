/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:15:52 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/01 14:23:15 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand(char *str, t_arg **arg)
{
	int		i = 0;
	int		k;
	char	*ret = NULL;
	char	*env = NULL;
	char	*left = NULL;
	char	*right = NULL;
	char	*joined = NULL;
	char	*new_str = ft_strdup(str);  // point de départ

	while (new_str[i])
	{
		if (new_str[i] == '$')
		{
			k = 1;
			while (new_str[i + k] && (ft_isalnum(new_str[i + k]) || new_str[i + k] == '_'))
				k++;

			ret = ft_substr(new_str, i + 1, k - 1);
			env = getenv(ret);
			free(ret);
			if (!env)
				env = "";

			left = ft_substr(new_str, 0, i);
			right = ft_strdup(&new_str[i + k]);

			joined = ft_strjoin(left, env);
			free(left);
			left = ft_strjoin(joined, right);
			free(joined);
			free(right);
			free(new_str);

			new_str = left;
			i += ft_strlen(env);  // on saute la variable déjà expandée
			continue;
		}
		i++;
	}

	free((*arg)->value);
	(*arg)->value = new_str;
}


static int	need_expansion(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '$' && str[i + 1])
		{
			if (ft_isalpha(str[i + 1]) || str[i] == '_')
				return (1);			
		}
		i++;
	}
	return (0);
}

void	expanser(t_arg **arg)
{
	t_arg *curr;

	if (!arg || !*arg || !(*arg)->value)
		return ;

	curr = *arg;
	while (curr)
	{
		if (curr->type == T_DQUOTE || curr->type == T_VAR)
		{
			if (need_expansion(curr->value))
				expand(curr->value, &curr);
		}
		curr = curr->next;
	}
}


// int main(int ac, char **av, char **envp)
// {	
// 	t_arg *arg;
// 	arg = malloc(sizeof(t_arg));
// 	arg->value = ft_strdup("hello world $HOME $PWD");
// 	arg->type = T_DQUOTE;
// 	arg->next = NULL;
// 	expanser(arg);
// 	printf("%s\n", arg->value);
// 	free(arg->value);
// 	free(arg);
// }