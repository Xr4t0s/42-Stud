/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:50:56 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/26 18:56:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	check_data(t_data *d, char *filename)
{
	if (!parse_file(d, filename))
		return (0);
	if (!check_map_data(*d) ||!check_param(*d))
		return (0);
	return (1);
}
