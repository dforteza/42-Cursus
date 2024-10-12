/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:08:30 by dforteza          #+#    #+#             */
/*   Updated: 2024/10/12 18:19:26 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(const char str, va_list args)
{
	int	size;

	size = 0;
	if (str == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (str == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (str == 'p')
		size += ft_putptr(va_arg(args, unsigned long long));
	else if (str == 'd' || str == 'i')
		size += ft_putnbr(va_arg(args, int));
	else if (str == 'u')
		size += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (str == 'x' || str == 'X')
		size += ft_puthex(va_arg(args, unsigned int), str);
	else if (str == '%')
		size += ft_putchar('%');
	else
		size += ft_putchar(str);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		size;

	size = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			size += ft_format(str[i + 1], args);
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == '\0')
		{
			va_end(args);
			return (size);
		}
		else
			size += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (size);
}
