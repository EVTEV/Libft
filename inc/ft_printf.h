/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:28:45 by acaes             #+#    #+#             */
/*   Updated: 2024/11/09 19:35:18 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

# ifdef __linux__
#  define NULL_STR "(null)"
#  define NULL_PTR "(nil)"
# else
#  define NULL_STR "(null)"
#  define NULL_PTR "0x0"
# endif

int				ft_printf(const char *format, ...);
size_t			ft_strlen(const char *s);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_putptr(void *ptr);
ssize_t			ft_putnbr(int n);
int				ft_putuns(unsigned int n);
int				ft_puthexlow(unsigned long n);
int				ft_puthexup(unsigned long n);

#endif
