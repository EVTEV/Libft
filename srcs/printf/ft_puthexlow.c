/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:14:00 by acaes             #+#    #+#             */
/*   Updated: 2024/12/03 17:09:18 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_puthexlow(unsigned long n)
{
	int		i;

	if (n == 0)
		return (ft_putchar('0'));
	i = 0;
	if (n >= 16)
	{
		i += ft_puthexlow(n / 16);
		if (i < 0)
			return (-1);
	}
	if (ft_putchar("0123456789abcdef"[n % 16]) < 0)
		return (-1);
	i++;
	return (i);
}
