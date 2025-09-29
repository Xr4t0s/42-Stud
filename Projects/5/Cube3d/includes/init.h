/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 00:16:43 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/28 21:27:52 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include "cub3d.h"

typedef struct s_data	t_data;
typedef struct s_player	t_player;
typedef struct s_map	t_map;

void	init(t_data *data);
void	init_map(t_map *map);
void	init_player(t_player *player);

#endif