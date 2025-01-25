/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:49:37 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/21 18:59:47 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				size;
	unsigned char	bit;
	

	size = 8;
	while (size--)
	{
		bit = (octet >> size & 1) + '0';
		write(1, &bit, 1);
	} 
}

int	main(int ac, char **av)
{
	unsigned char s = 15;
	print_bits(s);
	return (0);
}