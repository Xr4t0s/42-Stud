/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 03:30:44 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/11 02:40:34 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_pwd(char **bin)
{
	char	*path;

	if (bin[1])
		return (printf("Too many arguments\n"), NULL);
	path = getcwd(NULL, 0);
	return (path);
}

// int main()
// {
// 	char *bin[2];

// 	bin[0] = "pwd";
// 	bin[1] = NULL;
// 	char *path = ft_pwd(bin);
// 	printf("%s\n", path);
// 	free(path);
// }
