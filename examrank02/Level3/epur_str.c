/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:56:59 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/23 13:42:16 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void ft_epur_str(char *str)
{
	int	i;
	int	j;
	int	k;
	int	cont;

	// TRIM INIT
	i = 0;
	while (ft_is_space(str[i]))
		i++;
	// TRIM FINAL
	k = 0;
	while (str[k])
		k++;
	k--;
	while (ft_is_space(str[k]))
		k--;
	// ALGORITMO
	while (i <= k)
	{
		cont = 0;
		j = i;
		while (ft_is_space(str[j]) == 1)
		{
			cont++;
			j++;
		}
		if (cont <= 1)
			write(1, &str[i], 1);
		else
		{
			write(1, " ", 1);
			i = j;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_epur_str(av[1]);
	write(1, "\n", 1);
	return (0);
}