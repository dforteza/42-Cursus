/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:21:22 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/20 20:37:32 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_last_word(char *str)
{
	int	i;
	
	// 1-Recorrer str hasta el final
	i = 0;
	while (str[i])
		i++;
	i--;
	// 2-Recorrer hacia atras mientras encuentre esp
	while (str[i])
	{
		if (str[i] != ' ')
			break ;
		i--;
	}
	// 3-Recorrer mientras no encuentre esp
	while (str[i] > 32 && str[i] <= 126)
		i--;
	i++;
	// 4-Imprimir palabra hasta esp
	while (str[i])
	{
		if (str[i] != ' ')
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_last_word(av[1]);
	write(1, "\n", 1);
	return (0);
}