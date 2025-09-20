/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 06:38:38 by nitadros          #+#    #+#             */
/*   Updated: 2025/09/20 19:42:35 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "cube3d.h"

// typedef struct s_data
// {
//  struct s_mlx *mlx;
//  struct s_player *player;
//  struct s_minimap *minimap;
// } t_data;

// typedef struct s_mlx
// {
//  void *mlx;
//  void *win;
// } t_mlx;

typedef struct s_player
{
 int x;
 int y;

 double xP;
 double yP;
 double angle;
 double fov;
 double fov_rot;
 double	rot;
 double move_speed;
} t_player;

// typedef struct s_minimap
// {
//  char **map;
//  void *bg;
//  void *wall;
//  void *player;
//  void *bg4;
// } t_minimap;


// int main();
// int minimap(char **map, t_data *data);
// int movements(t_data *data);

#endif