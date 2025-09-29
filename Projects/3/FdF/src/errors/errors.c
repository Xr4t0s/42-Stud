/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:28:41 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/13 17:28:41 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_return(char *error, int exit_code, t_controller *controller)
{
	if (error)
		ft_printf("%s\n", error);
	free_controller(controller);
	exit(exit_code);
}
