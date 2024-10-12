/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:21:25 by dforteza          #+#    #+#             */
/*   Updated: 2024/10/12 18:05:57 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_puthex_recursive(unsigned int n, char *hex_digits)
{
	if (n >= 16)
		ft_puthex_recursive(n / 16, hex_digits);
	ft_putchar(hex_digits[n % 16]);
}

int	ft_puthex(unsigned int n, char str)
{
	char	hex_digits[16];
	int		i;

	if (n == 0)
		return (ft_putchar('0'));
	i = 0;
	while (i < 10)
	{
		hex_digits[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		if (str == 'x')
			hex_digits[i] = (i - 10) + 'a';
		else if (str == 'X')
			hex_digits[i] = (i - 10) + 'A';
		i++;
	}
	ft_puthex_recursive(n, hex_digits);
	return (ft_hex_len(n));
}
