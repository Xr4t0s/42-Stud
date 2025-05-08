/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 03:40:32 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/08 04:33:48 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_cd(char **bin, char **env)
{
	char	*pwd[2];
	char	**tmp;

	i = 0;
	if (bin[2])
	{
		printf("Too many arguments\n");
		return (env);
	}
	pwd[0] = "PWD";
	pwd[1] = NULL;
	tmp = duplicate_env("PWD", env);
	tmp = duplicate_env("OLDPWD", tmp);
	tmp = add_var(ft_strjoin("OLDPWD=", ft_pwd(pwd)), tmp);
	if (chdir(bin[1]) == -1)
		return (perror(""), env);
	env = add_var(ft_strjoin("PWD=", ft_pwd(pwd)), tmp);
	env = tmp;
	return (env);
}

// int main(int ac, char **av)
// {
// 	char **env;
// 	char **tmp;
// 	(void)ac;
// 	av++;
// 	env = malloc(sizeof(char *) * 3);
// 	env[0] = ft_strdup("PWD=khgvsdhf");
// 	env[1] = ft_strdup("OLDPWD=ugjhbjnm");
// 	env[2] = NULL;

// 	tmp = env;
// 	env = ft_cd(av, env);
// 	if (!env)
// 		env = tmp;
// 	int i = 0;
// 	while(env[i])
// 	{
// 		printf("%s\n", env[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while(env[i])
// 	{
// 		free(env[i]);
// 		i++;
// 	}
// 	free(env);
// 	printf("%s\n", ft_pwd(av));
// }