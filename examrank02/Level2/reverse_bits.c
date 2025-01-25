/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:00:36 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/21 19:27:07 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				size;
	unsigned char	res;
	
	res = 0;
	size = 8;
	while (size--)
	{
		res = res << 1;
		res = res | (octet & 1);
		octet = octet >> 1;
	}
	return (res);
}

int	main(int ac, char **av)
{
	unsigned char s = 16;
	
	printf("%d\n",reverse_bits(s));
	return (0);
}