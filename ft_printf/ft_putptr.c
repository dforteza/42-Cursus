/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:42:28 by dforteza          #+#    #+#             */
/*   Updated: 2024/10/12 12:52:50 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long long ptr)
{
	int	len;

	if (ptr == 0)
		return (1);
	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

static void	ft_putptr_recursive(unsigned long long ptr, char *hex_digits)
{
	if (ptr >= 16)
		ft_putptr_recursive(ptr / 16, hex_digits);
	ft_putchar(hex_digits[ptr % 16]);
}

int	ft_putptr(unsigned long long ptr)
{
	char	hex_digits[16];
	int		i;

	if (ptr == 0)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	i = 0;
	while (i < 10)
	{
		hex_digits[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		hex_digits[i] = (i - 10) + 'a';
		i++;
	}
	ft_putptr_recursive(ptr, hex_digits);
	return (ft_ptr_len(ptr) + 2);
}
