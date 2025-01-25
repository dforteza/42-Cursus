/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:20:44 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/22 12:46:01 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_wdmatch(char *s1, char *s2)
{
	int	i;
	int	j;
	int	cont;

	cont = 0;
	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				cont++;
				// printf("CONT: %d\n", cont);
				// printf("i : %d  : %c///", i, s1[i]);
				// printf("j : %d  : %c\n\n", j, s2[j]);
				if (cont != ft_strlen(s1))
					j++;
				break ;
			}
			j++;
		}
		i++;
	}
	if (cont == ft_strlen(s1))
	{
		i = 0;
		while (s1[i])
		{
			write(1, &s1[i], 1);
			i++;
		}
	}
}


int	main(int ac, char **av)
{
	if (ac == 3)
		ft_wdmatch(av[1],av[2]);
	write(1,"\n", 1);
	return (0);
}