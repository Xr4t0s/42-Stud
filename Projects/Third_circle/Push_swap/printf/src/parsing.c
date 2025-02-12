/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:09:40 by nitadros          #+#    #+#             */
/*   Updated: 2024/12/02 16:28:58 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_flag(char c)
{
	t_flags	s;

	s = init();
	if (c == s.character)
		return (1);
	else if (c == s.string)
		return (2);
	else if (c == s.pointer)
		return (3);
	else if (c == s.decimal)
		return (4);
	else if (c == s.integer)
		return (5);
	else if (c == s.uns_integer)
		return (6);
	else if (c == s.hex_low)
		return (7);
	else if (c == s.hex_up)
		return (8);
	else if (c == s.percent)
		return (9);
	else
		return (0);
}
