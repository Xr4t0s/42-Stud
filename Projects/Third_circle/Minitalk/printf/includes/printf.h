/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:59:39 by nitadros          #+#    #+#             */
/*   Updated: 2024/11/15 20:33:47 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags
{
	char	character;
	char	string;
	char	pointer;
	char	decimal;
	char	integer;
	char	uns_integer;
	char	hex_low;
	char	hex_up;
	char	percent;
}	t_flags;

t_flags	*init(void);

#endif