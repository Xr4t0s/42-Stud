/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:59:39 by nitadros          #+#    #+#             */
/*   Updated: 2024/12/02 16:57:20 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

t_flags	init(void);
int		find_flag(char c);

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmembytes, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_putnbr(int nb);
void	ft_putchar(char c);
int		ft_unsigned_putnbr(unsigned int nb);
int		ft_putnbr_base(unsigned int nbr);
int		ft_putnbr_base_maj(unsigned int nbr);
int		ft_printf(const char *s, ...);
int		print_addr(unsigned long long addr);
int		parse(int flag, va_list ptr);
int		ft_numlen(int n);

int		string(char *s);
int		character(int c);

#endif