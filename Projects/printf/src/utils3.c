/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nitadros <nitadros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:32:22 by nitadros          #+#    #+#             */
/*   Updated: 2024/12/02 16:37:02 by nitadros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr)
{
	long		nbrl;
	const char	*base = "0123456789abcdef";
	int			len;

	len = 0;
	nbrl = (long)nbr;
	if (nbrl >= (int)ft_strlen(base))
		len += ft_putnbr_base(nbrl / ft_strlen(base));
	write(1, &base[nbrl % ft_strlen(base)], 1);
	len++;
	return (len);
}

int	ft_putnbr_base_maj(unsigned int nbr)
{
	long		nbrl;
	const char	*base = "0123456789ABCDEF";
	int			len;

	len = 0;
	nbrl = (long)nbr;
	if (nbrl >= (int)ft_strlen(base))
		len += ft_putnbr_base_maj(nbrl / ft_strlen(base));
	write(1, &base[nbrl % ft_strlen(base)], 1);
	len++;
	return (len);
}
