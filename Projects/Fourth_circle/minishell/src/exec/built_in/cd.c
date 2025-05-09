/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 03:40:32 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/09 23:36:01 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_cd(char **bin, char **env)
{
	char *pwd[2];

	if (bin[2])
	{
		printf("Too many arguments\n");
		return (env);
	}
	pwd[0] = "PWD";
	pwd[1] = NULL;
	env = duplicate_env("PWD", env);
	env = duplicate_env("OLDPWD", env);
	env = add_var(ft_strjoin("OLDPWD=", ft_pwd(pwd)), env);
	if (!bin[1])
		bin[1] = ft_strdup(find_var(env, "HOME="));
	if (chdir(bin[1]) == -1)
		return (perror("cd"), env);
	env = add_var(ft_strjoin("PWD=", ft_pwd(pwd)), env);
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