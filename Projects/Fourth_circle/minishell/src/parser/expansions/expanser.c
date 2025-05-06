/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:15:52 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/06 18:59:49 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand_utils(t_expansion *exp, int *i, int *k, t_data *data)
{
	exp->ret = ft_substr(exp->new_str, *i + 1, *k - 1);
	if (ft_strncmp(exp->ret, "\?", 1) == 0)
		exp->env = ft_itoa(data->last_code);
	else
		exp->env = getenv(exp->ret);
	free(exp->ret);
	if (!exp->env)
		exp->env = "";
	exp->left = ft_substr(exp->new_str, 0, *i);
	exp->right = ft_strdup(&exp->new_str[*i + *k]);
	exp->joined = ft_strjoin(exp->left, exp->env);
	free(exp->left);
	exp->left = ft_strjoin(exp->joined, exp->right);
	free(exp->joined);
	free(exp->right);
	free(exp->new_str);
	exp->new_str = exp->left;
}

static void	init_expansions(t_expansion *exp, char *str)
{
	exp->ret = NULL;
	exp->env = NULL;
	exp->left = NULL;
	exp->right = NULL;
	exp->joined = NULL;
	exp->new_str = ft_strdup(str);
}

static void	expand(char *str, t_arg **arg, t_data *data)
{
	int			i;
	int			k;
	t_expansion	exp;

	i = 0;
	init_expansions(&exp, str);
	while (exp.new_str[i])
	{
		if (exp.new_str[i] == '$')
		{
			if (exp.new_str[i + 1] == '?')
				k = 2;
			else
			{
				k = 1;
				while (exp.new_str[i + k] && (ft_isalnum(exp.new_str[i + k])
						|| exp.new_str[i + k] == '_'))
					k++;
			}
			expand_utils(&exp, &i, &k, data);
			i += ft_strlen(exp.env);
			continue ;
		}
		i++;
	}
	free((*arg)->value);
	(*arg)->value = exp.new_str;
}

static int	need_expansion(char *str)
{
	int	i;
	int	mark;

	i = 0;
	mark = 0;
	while (str[i])
	{
		if (str[i] == '"')
			mark = 1;
		else if (str[i] == '"' && mark == 1)
			mark = 0;
		if (str[i] == '\'' && mark != 1)
			return (0);
		if (str[i] == '$' && str[i + 1])
		{
			if (ft_isalpha(str[i + 1]) || str[i + 1] == '_'
				|| str[i + 1] == '?')
				return (1);
		}
		i++;
	}
	return (0);
}

void	expanser(t_arg **arg, t_data *data)
{
	t_arg	*curr;

	if (!arg || !*arg || !(*arg)->value)
		return ;
	curr = *arg;
	while (curr)
	{
		if (curr->type == T_DQUOTE || curr->type == T_VAR
			|| curr->type == T_WORD)
		{
			if (need_expansion(curr->value))
				expand(curr->value, &curr, data);
		}
		curr = curr->next;
	}
}
