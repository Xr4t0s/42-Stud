/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:16:11 by nitadros          #+#    #+#             */
/*   Updated: 2025/02/10 03:22:23 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/types/siginfo_t.h>
#include <signal.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

typedef struct s_global
{
	unsigned char	current;
	unsigned char	position;
	int				i;
}	t_global;
