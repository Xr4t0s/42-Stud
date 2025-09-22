/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 23:38:55 by engiacom          #+#    #+#             */
/*   Updated: 2025/09/22 15:11:30 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

typedef	struct s_move
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	l;
	int	r;
	int	m;

}	t_move;

typedef struct s_mouse
{
	int prev_x;
	int	warping;
}	t_mouse;

int	key_press(int key, t_data *data);
int	key_release(int keycode, t_data *data);
int	handle_keypress(int keycode, t_data *data);

void screen(t_data *data);

#endif