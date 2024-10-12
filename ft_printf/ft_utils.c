/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:18:59 by dforteza          #+#    #+#             */
/*   Updated: 2024/10/11 14:30:50 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char	c;
	int		len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putstr("-2147483648");
		return (len);
	}
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		len += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	len += ft_putchar(c);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	c;
	int		len;

	len = 0;
	if (n > 9)
		len += ft_putnbr_unsigned(n / 10);
	c = (n % 10) + '0';
	len += ft_putchar(c);
	return (len);
}
