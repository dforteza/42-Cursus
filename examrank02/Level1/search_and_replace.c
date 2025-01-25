/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:35:06 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/15 20:00:55 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_search_and_replace(char *str, char *s, char *r)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == *s)
			write(1, r, 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 4)
		ft_search_and_replace(av[1], av[2], av[3]);
	write(1, "\n", 1);
	return (0);
}