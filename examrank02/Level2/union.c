/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:27:12 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/21 12:33:10 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_double_pos(char s, char *str, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (str[i] == s)
			return (0);
		i++;
	}
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		 if (check_double_pos(s1[i], s1, i))
		 	write(1, &s1[i], 1);
		i++;
	}
	j = 0;
	while(s2[j])
	{
		if (check_double_pos(s2[j], s1, i) && check_double_pos(s2[j], s2, j))
			write(1, &s2[j], 1);
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write (1, "\n", 1);
	return (0);
}