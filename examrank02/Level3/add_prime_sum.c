/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:51:37 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/22 20:38:49 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	minus;
	int	n;

	i = 0;
	while (str[i] == '\t' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	if (minus % 2 != 0)
		n *= (-1);
	return (n);
}

int	ft_prime(int n)
{
	int	i;
	
	if (n < 0 || n == 1)
		return (0);
	else if (n == 2)
		return (1);
	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);	
}

void ft_putnbr(int n)
{
	char c;
	
	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	ft_add_prime_sum(char *str)
{
	int	n;
	int	sum;
	int	i;
	
	n = ft_atoi(str);
	if (n < 0)
		return (0);
	sum = 0;
	i = 2;
	while (i <= n)
	{
		if (ft_prime(i))
			sum += i;
		i++;
	}
	return (sum);
}


int	main(int ac, char **av)
{
	if (ac != 2)
		write(1, "0", 1);
	else
		ft_putnbr(ft_add_prime_sum(av[1]));
	write(1, "\n", 1);
	return (0);
}