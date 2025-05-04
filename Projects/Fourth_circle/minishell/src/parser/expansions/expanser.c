/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:15:52 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/04 04:54:34 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand_utils(t_expansion *exp, int *i, int *k)
{
	exp->ret = ft_substr(exp->new_str, *i + 1, *k - 1);
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

static void	expand(char *str, t_arg **arg)
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
			k = 1;
			while (exp.new_str[i + k] && (ft_isalnum(exp.new_str[i + k])
					|| exp.new_str[i + k] == '_'))
				k++;
			expand_utils(&exp, &i, &k);
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

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1])
		{
			if (ft_isalpha(str[i + 1]) || str[i + 1] == '_')
				return (1);
		}
		i++;
	}
	return (0);
}

void	expanser(t_arg **arg)
{
	t_arg	*curr;

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
