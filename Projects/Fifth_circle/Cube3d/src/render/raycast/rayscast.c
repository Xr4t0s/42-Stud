/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayscast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:17:11 by engiacom          #+#    #+#             */
/*   Updated: 2025/09/19 22:41:50 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "raycast.h"
#include <math.h>

#define MAX_DIST 15.0

void	draw_line(char *addr, int x0, int y0, int x1, int y1, int color, int bpp, int line_len)
{
	// Algorithme de Bresenham pour tracer une ligne de (x0,y0) à (x1,y1)
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx;
	int sy;
	int err = dx - dy;

	// Direction du pas en X
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;

	// Direction du pas en Y
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;

	while (1)
	{
		// Évite d’écrire hors image (test minimal)
		if (x0 >= 0 && y0 >= 0)
		{
			char *pixel = addr + (y0 * line_len + x0 * (bpp / 8));
			*(unsigned int *)pixel = color;
		}
		// Point d’arrivée atteint
		if (x0 == x1 && y0 == y1)
			break;

		// Mise à jour d’erreur et déplacements
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

int	render(void *param)
{
	// Rendu principal : raycasting colonne par colonne + minimap
	t_data	*data = (t_data *)param;

	static void *img = NULL;
	static char *addr;
	static int bpp, line_len, endian;

	// Création du buffer image une seule fois
	if (img == NULL)
	{
		img = mlx_new_image(data->mlx.mlx, 1080, 720);
		addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);
	}
	struct timeval tv;
    gettimeofday(&tv, NULL);
	long long start = (long long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
	int x = 0;
	while (x < 1080)
	{
		t_raycast raycast;

		// Position du joueur (échelle : tes positions semblent en /10)
		raycast.posX = data->player.xP / 10.0;
		raycast.posY = data->player.yP / 10.0;

		// Direction de vue du joueur (angle en radians)
		raycast.dirX = cos(data->player.angle); // X=0,Y=-1 → Nord si angle = -pi/2
		raycast.dirY = sin(data->player.angle);

		// Plan caméra (contrôle le FOV)
		raycast.planeX = -raycast.dirY * tan(data->player.fov / 2);
		raycast.planeY =  raycast.dirX * tan(data->player.fov / 2);

		// Coordonnée caméra en X dans l’espace écran [-1, 1]
		raycast.cameraX = 2.0f * (float)x / 1080.0f - 1.0f;

		// Direction du rayon pour cette colonne écran
		raycast.rayDirX = raycast.dirX + raycast.planeX * raycast.cameraX;
		raycast.rayDirY = raycast.dirY + raycast.planeY * raycast.cameraX;

		// Case de la grille (carte) où commence le rayon
		raycast.mapX = (int)raycast.posX;
		raycast.mapY = (int)raycast.posY;

		// Distances à parcourir entre deux intersections de grille sur X/Y
		raycast.deltaDistX = fabs(1.0 / raycast.rayDirX);
		raycast.deltaDistY = fabs(1.0 / raycast.rayDirY);

		// Détermination du sens des pas sur X
		if (raycast.rayDirX < 0)
			raycast.stepX = -1;
		else
			raycast.stepX = 1;

		// Détermination du sens des pas sur Y
		if (raycast.rayDirY < 0)
			raycast.stepY = -1;
		else
			raycast.stepY = 1;

		// Distance du rayon jusqu’à la première arête verticale rencontrée
		if (raycast.rayDirX < 0)
			raycast.sideDistX = (raycast.posX - raycast.mapX) * raycast.deltaDistX;
		else
			raycast.sideDistX = (raycast.mapX + 1.0 - raycast.posX) * raycast.deltaDistX;

		// Distance du rayon jusqu’à la première arête horizontale rencontrée
		if (raycast.rayDirY < 0)
			raycast.sideDistY = (raycast.posY - raycast.mapY) * raycast.deltaDistY;
		else
			raycast.sideDistY = (raycast.mapY + 1.0 - raycast.posY) * raycast.deltaDistY;

		// DDA : on avance d’une case à la fois jusqu’au mur ou distance max
		int   hit = 0;
		float distance_travelled = 0.0f;

		while (hit == 0 && distance_travelled < MAX_DIST)
		{
			if (raycast.sideDistX < raycast.sideDistY)
			{
				distance_travelled = raycast.sideDistX;
				raycast.sideDistX += raycast.deltaDistX;
				raycast.mapX += raycast.stepX;
				raycast.side = 0; // impact sur une face verticale
			}
			else
			{
				distance_travelled = raycast.sideDistY;
				raycast.sideDistY += raycast.deltaDistY;
				raycast.mapY += raycast.stepY;
				raycast.side = 2; // impact sur une face horizontale
			}

			// Test de collision avec un mur ('1')
			if (data->map.map[raycast.mapY][raycast.mapX] == '1' || data->map.map[raycast.mapY][raycast.mapX] == 'D')
				hit = 1;
			if (data->map.map[raycast.mapY][raycast.mapX] == 'D' && data->raycast.door > 0 && (fabs(raycast.sideDistX) <= 2 || fabs(raycast.sideDistY) <= 2) && raycast.cameraX >= -0.30 && raycast.cameraX <= 0.30)
			{
				// printf("%f\n%f\n", raycast.sideDistX, raycast.sideDistY);
				data->map.map[raycast.mapY][raycast.mapX] = '*';
				data->raycast.door *= -1;
				hit = 0;
			}
			else if (data->map.map[raycast.mapY][raycast.mapX] == '*' && data->raycast.door > 0 && (fabs(raycast.sideDistX) <= 2 || fabs(raycast.sideDistY) <= 2) && raycast.cameraX >= -0.30 && raycast.cameraX <= 0.30)
			{
				// printf("%f\n%f\n", raycast.sideDistX, raycast.sideDistY);
				data->map.map[raycast.mapY][raycast.mapX] = 'D';
				data->raycast.door *= -1;
				hit = 1;
			}

			// Affine l’orientation de la face touchée (0→1 pour Est/Ouest, 2→3 pour Nord/Sud)
			if (raycast.side == 2)
			{
				if (raycast.posY > raycast.mapY)
					raycast.side = 3; // face sud
			}
			else
			{
				if (raycast.posX > raycast.mapX)
					raycast.side = 1; // face est
			}
		}

		// Distance perpendiculaire au mur (corrige l’effet fish-eye)
		float finalDist;
		if (hit)
		{
			if (raycast.side <= 1)
			{
				raycast.perpWallDist =
					(raycast.mapX - raycast.posX + (1 - raycast.stepX) / 2.0) / raycast.rayDirX;
			}
			else
			{
				raycast.perpWallDist =
					(raycast.mapY - raycast.posY + (1 - raycast.stepY) / 2.0) / raycast.rayDirY;
			}
			// Clamp par sécurité
			if (raycast.perpWallDist < MAX_DIST)
				finalDist = raycast.perpWallDist;
			else
				finalDist = MAX_DIST;
		}
		else
		{
			finalDist = MAX_DIST;
		}

		// Distance utilisée pour la hauteur de ligne (fallback si pas de hit)
		double dist;
		if (hit)
			dist = raycast.perpWallDist;
		else
			dist = 1e9;

		// Calcul de la hauteur de la “slice” de mur pour cette colonne
		int lineHeight;
		if (dist > 0.0)
			lineHeight = (int)(720.0 / dist);
		else
			lineHeight = 720;

		int drawStart  = (720 - lineHeight) / 2;
		int drawEnd    = drawStart + lineHeight - 1;

		if (drawStart < 0)
			drawStart = 0;
		if (drawEnd >= 720)
			drawEnd = 720 - 1;

		// Couleurs (ARGB 0x00RRGGBB ici, selon ton mlx)
		unsigned int ceil_col  = 0x00303030; // plafond
		unsigned int floor_col = 0x00605030; // sol

		// Couleur du mur selon la face frappée (ombrage simple)
		unsigned int wall_col;
		if (raycast.side == 1)
			wall_col = 0x00457568; // face est
		else if (raycast.side == 2)
			wall_col = 0x0000FF00; // face nord
		else if (raycast.side == 3)
			wall_col = 0x0000FFFF; // face sud
		else
			wall_col = 0x00AAAAAA; // face ouest

		// --- Remplissage plafond (y : 0 → drawStart-1)
		int y = 0;
		while (y < drawStart)
		{
			char *p = addr + (y * line_len + x * (bpp / 8));
			*(unsigned int *)p = ceil_col;
			y++;
		}

		// --- Colonne du mur (y : drawStart → drawEnd)
		y = drawStart;
		while (y <= drawEnd)
		{
			char *p = addr + (y * line_len + x * (bpp / 8));
			*(unsigned int *)p = wall_col;
			y++;
		}

		// --- Remplissage sol (y : drawEnd+1 → 719)
		y = drawEnd + 1;
		while (y < 720)
		{
			char *p = addr + (y * line_len + x * (bpp / 8));
			*(unsigned int *)p = floor_col;
			y++;
		}

		// Point d’impact du rayon (utile pour la minimap / debug)
		float hitX = raycast.posX + raycast.rayDirX * finalDist;
		float hitY = raycast.posY + raycast.rayDirY * finalDist;

		// Trace le rayon sur la minimap (échelle *10)
		draw_line(
			addr,
			(int)(raycast.posX * 10.0 + 1.5), (int)(raycast.posY * 10.0),
			(int)(hitX * 10.0),               (int)(hitY * 10.0),
			0x00FFFF00, bpp, line_len
		);

		x++;
	}
	data->raycast.door = -1;

	// Dessine la minimap par-dessus
	minimap(data->map.map, data, addr, bpp, line_len);

	// Affiche le buffer à l’écran
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, img, 0, 0);
	gettimeofday(&tv, NULL);
	long long end = (long long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
	while (end - start <= 32)
	{
		usleep(100);
		gettimeofday(&tv, NULL);
		end = (long long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
	}
	return (0);
}

