/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:00:26 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/17 19:24:19 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	n;
	int	i;
	int	cont;
	int	traza = 0;

	cont = 0;
	i = 0;
	while (str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			cont++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = 10 * n + (str[i] - '0');
		i++;
		traza++;
	}
	if (cont % 2 != 0)
		n *= (-1);
	return (n);
}

int	main(int ac, char **av)
{
	printf("atoi: %d\n", ft_atoi(av[1]));
	return (0);
}