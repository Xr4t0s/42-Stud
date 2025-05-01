/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:22:27 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/30 16:32:37 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    main(int ac, char **av, char **env)
{
    t_data data;

    data.arg = NULL;
    read_input(&data);
    rl_clear_history();
}
