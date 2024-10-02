/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:08:30 by dforteza          #+#    #+#             */
/*   Updated: 2024/09/30 20:18:34 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

static int	ft_putnbr_base_fd(unsigned long nbr, int base, int is_upper, int fd)
{
	char	*digits;
	int		count;

	count = 0;
	if (is_upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (nbr >= (unsigned long)base)
		count += ft_putnbr_base_fd(nbr / base, base, is_upper, fd);
	ft_putchar_fd(digits[nbr % base], fd);
	count++;
	return (count);
}

static int	ft_putstr_fd_count(char *s, int fd)
{
	int count = 0;

	while (*s)
	{
		ft_putchar_fd(*s++, fd);
		count++;
	}
	return (count);
}

static int	ft_putnbr_fd_count(int n, int fd)
{
	char	*str;
	int		count;

	str = ft_itoa(n);
	count = ft_putstr_fd_count(str, fd);
	free(str);
	return (count);
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
				count += ft_putstr_fd_count(va_arg(args, char *), 1);
			else if (format[i] == 'd' || format[i] == 'i')
				count += ft_putnbr_fd_count(va_arg(args, int), 1);
			else if (format[i] == 'c')
			{
				ft_putchar_fd((char)va_arg(args, int), 1);
				count++;
			}
			else if (format[i] == 'u')
				count += ft_putnbr_base_fd(va_arg(args, unsigned int), 10, 0, 1);
			else if (format[i] == 'x')
				count += ft_putnbr_base_fd(va_arg(args, unsigned int), 16, 0, 1);
			else if (format[i] == 'X')
				count += ft_putnbr_base_fd(va_arg(args, unsigned int), 16, 1, 1);
			else if (format[i] == 'p')
			{
				count += ft_putstr_fd_count("0x", 1);
				count += ft_putnbr_base_fd((unsigned long)va_arg(args, void *), 16, 0, 1);
			}
			else if (format[i] == '%')
			{
				ft_putchar_fd('%', 1);
				count++;
			}
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}