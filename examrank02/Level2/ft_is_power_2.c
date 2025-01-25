/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_power_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:51:58 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/21 13:04:16 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
	{
		printf("%d\n", n);
		n /= 2;
	}
	printf("%d\n", n);
	if (n == 1)
		return (1);
	return (0);
}
int	main(void)
{
	unsigned int n = 32;
	printf("\n%d\n", is_power_of_2(n));
	return (0);
}