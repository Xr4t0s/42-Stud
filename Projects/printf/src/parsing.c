/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:09:40 by nitadros          #+#    #+#             */
/*   Updated: 2024/11/15 20:14:27 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	find_flag(char c)
{
	t_flags	s;
	
	if (c == s.character)
		return (1);
	else if (c == s.string)
		return (2);
	else if (c == s.pointer)
		return (2);
	else if (c == s.decimal)
		return (2);
	else if (c == s.integer)
		return (2);
	else if (c == s.uns_integer)
		return (2);
	else if (c == s.hex_low)
		return (2);
	else if (c == s.hex_low)
		return (2);
	else if (c == s.percent)
		return (2);
	else
		return (0);
}
