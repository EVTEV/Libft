/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:36:05 by acaes             #+#    #+#             */
/*   Updated: 2024/12/03 17:08:33 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_flag(const char *format, va_list *args)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (*format == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (*format == 'd' || *format == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (*format == 'u')
		return (ft_putuns(va_arg(*args, unsigned int)));
	else if (*format == 'x')
		return (ft_puthexlow(va_arg(*args, unsigned int)));
	else if (*format == 'X')
		return (ft_puthexup(va_arg(*args, unsigned int)));
	else if (*format == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(*format));
}

int	ft_format(const char *format, va_list *args)
{
	int	i;
	int	len;

	len = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			i = ft_flag(format, args);
			if (i == -1)
				return (-1);
			len += i;
		}
		else
		{
			i = ft_putchar(*format);
			if (i == -1)
				return (-1);
			len += i;
		}
		format++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	if (!format)
		return (0);
	len = 0;
	va_start(args, format);
	len = ft_format(format, &args);
	va_end(args);
	return (len);
}