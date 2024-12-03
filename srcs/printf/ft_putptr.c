/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:17:12 by acaes             #+#    #+#             */
/*   Updated: 2024/12/03 17:09:48 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	i;

	if (!ptr)
		return (ft_putstr(NULL_PTR));
	i = 0;
	i += ft_putstr("0x");
	if (i < 0)
		return (-1);
	return (i + ft_puthexlow((unsigned long)ptr));
}
