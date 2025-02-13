/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:48:29 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/13 17:48:29 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_init(t_map **map)
{
	if (!map)
		return ;
	(*map)->x = 0;	
	(*map)->y = 0;	
	(*map)->z = 0;
	if (!((*map)->coords = malloc(sizeof(int) * 400000)))
		ft_return("Error while map initialization", 0);
}
