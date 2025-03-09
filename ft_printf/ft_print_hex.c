/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:28:00 by dicosta-          #+#    #+#             */
/*   Updated: 2024/11/20 17:01:25 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(long int nbr, char *base)
{
	int	counter;

	counter = 0;
	if (nbr < 0)
	{
		counter += write(1, "-", 1);
	}
	if (nbr > 16)
	{
		counter += ft_print_hex(nbr / 16, base);
	}
	nbr %= 16;
	counter += write(1, &base[nbr], 1);
	return	(counter);
}