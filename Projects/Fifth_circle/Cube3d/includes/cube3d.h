/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 02:16:22 by nitadros          #+#    #+#             */
/*   Updated: 2025/06/24 05:13:23 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include "get_next_line_bonus.h"
# include "map.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_data
{
	t_map	map;
	t_mlx	mlx;	
}	t_data;

#endif
