/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:14:51 by nitadros          #+#    #+#             */
/*   Updated: 2024/12/02 16:29:16 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	init(void)
{
	t_flags	s;

	s.character = 'c';
	s.string = 's';
	s.pointer = 'p';
	s.decimal = 'd';
	s.integer = 'i';
	s.uns_integer = 'u';
	s.hex_low = 'x';
	s.hex_up = 'X';
	s.percent = '%';
	return (s);
}
