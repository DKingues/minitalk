/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:02:10 by dicosta-          #+#    #+#             */
/*   Updated: 2025/04/15 20:00:23 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		counter;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	counter = 0;
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == ' ')
		{
			i++;
			i += skipspaces(format, i, &counter);
			counter += ft_print_format(format[i], ap);
		}
		else if (format[i] == '%' && format[i + 1])
			counter += ft_print_format(format[++i], ap);
		else
			counter += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (counter);
}

int	skipspaces(const char *format, int i, int *counter)
{
	int	j;

	j = i;
	while (format[j] == ' ')
		j++;
	if (format[j] != '%')
		*counter += write(1, " ", 1);
	return (j - i);
}
