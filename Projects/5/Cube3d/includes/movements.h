/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 23:38:55 by engiacom          #+#    #+#             */
/*   Updated: 2025/09/28 22:28:22 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

typedef struct s_tmpvar
{
	double	a;
	char	first;
	char	secnd;
	double	ny;
	int		yp1;
	double	nx;
	int		xp1;
}	t_tmpvar;

typedef struct s_tmp_angle
{
	double	x;
	double	y;
	double	angle;
	char	xtestpos;
	char	xtestneg;
	char	ytestpos;
	char	ytestneg;
}	t_tmp_angle;

typedef struct s_move
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
	int	prev_x;
	int	warping;
}	t_mouse;

int		key_press(int key, t_data *data);
int		key_release(int keycode, t_data *data);
int		handle_keypress(int keycode, t_data *data);
int		check_angle(t_data *data);
int		go_right(t_data *d);
int		go_left(t_data *d);
int		go_up(t_data *d);
int		go_down(t_data *d);
void	screen(t_data *data);
int		close_window(void *data);

#endif