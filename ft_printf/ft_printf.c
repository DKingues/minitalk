/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:02:10 by dicosta-          #+#    #+#             */
/*   Updated: 2024/11/20 17:01:41 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char* format, ...)
{
    va_list ap;
    va_start(ap, format);
    int i;
    int counter;

    i = 0;
    counter = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            counter += ft_print_format(format[i], ap);
        }
        else
            counter += write(1, &format[i], 1);
        i++;
    }
    va_end(ap);
    return (counter);
}

/*int main(void)
{   
    char    *ptr = "DIOGO";
    
    ft_printf("DIOGO PRINTF\n\n");
    int ft_counter = ft_printf("DECIMAL: %d\nINT: %i\nHEX: %x\nHCHEX: %X\nSTRING: %s\nCHAR: %c\nPOINTER: %p\n\n", INT_MAX, INT_MIN, 3000, 3000, "Diogo", 'd', ptr);
    ft_printf("DIOGO COUNTER: %i\n\n\n", ft_counter);
    printf("ORIGINAL PRINTF\n\n");
    int og_counter = printf("DECIMAL: %d\nINT: %i\nHEX: %x\nHCHEX: %X\nSTRING: %s\nCHAR: %c\nPOINTER: %p\n\n", INT_MAX, INT_MIN, 3000, 3000, "Diogo", 'd', ptr);
    printf("COUNTER: %i\n\n\n", og_counter);
}*/
