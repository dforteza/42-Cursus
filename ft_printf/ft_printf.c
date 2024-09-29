/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:08:30 by dforteza          #+#    #+#             */
/*   Updated: 2024/09/29 17:21:49 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

static void	ft_putnbr_base_fd(unsigned long nbr, int base, int is_upper, int fd)
{
	char	*digits;

	if (is_upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (nbr >= (unsigned long)base)
		ft_putnbr_base_fd(nbr / base, base, is_upper, fd);
	ft_putchar_fd(digits[nbr % base], fd);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (format[i] == 'd' || format[i] == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (format[i] == 'c')
				ft_putchar_fd((char)va_arg(args, int), 1);
			else if (format[i] == 'u')
				ft_putnbr_base_fd(va_arg(args, unsigned int), 10, 0, 1);
			else if (format[i] == 'x')
				ft_putnbr_base_fd(va_arg(args, unsigned int), 16, 0, 1);
			else if (format[i] == 'X')
				ft_putnbr_base_fd(va_arg(args, unsigned int), 16, 1, 1);
			else if (format[i] == 'p')
			{
				ft_putstr_fd("0x", 1);
				ft_putnbr_base_fd((unsigned long)va_arg(args, void *), 16, 0, 1);
			}
			else if (format[i] == '%')
				ft_putchar_fd('%', 1);
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}