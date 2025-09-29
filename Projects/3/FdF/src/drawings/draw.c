/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:30:30 by nitadros          #+#    #+#             */
/*   Updated: 2025/03/01 15:50:58 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	setup_bresenham(t_bresenham *b, t_line line)
{
	b->dx = abs(line.p2.x - line.p1.x);
	b->dy = abs(line.p2.y - line.p1.y);
	b->sx = 1;
	if (line.p1.x > line.p2.x)
		b->sx = -1;
	b->sy = 1;
	if (line.p1.y > line.p2.y)
		b->sy = -1;
	b->err = b->dx - b->dy;
}

static void	bresenham_loop(t_imgdata *img, t_line line, t_bresenham *b)
{
	while (1)
	{
		put_pixel(img, line.p1.x, line.p1.y, line.color);
		if (line.p1.x == line.p2.x && line.p1.y == line.p2.y)
			break ;
		b->e2 = 2 * b->err;
		if (b->e2 > -b->dy)
		{
			b->err -= b->dy;
			line.p1.x += b->sx;
		}
		if (b->e2 < b->dx)
		{
			b->err += b->dx;
			line.p1.y += b->sy;
		}
	}
}

void	draw_line(t_imgdata *img, t_line line)
{
	t_bresenham	b;

	setup_bresenham(&b, line);
	bresenham_loop(img, line, &b);
}
