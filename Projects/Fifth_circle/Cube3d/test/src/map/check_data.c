/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:50:56 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/26 00:20:47 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_data(t_data *d, char *filename)
{
	parse_file(d, filename);
	if (!check_map_data(*d) ||!check_param(*d))
		return (0);
	return (1);
}
