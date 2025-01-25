/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:26:49 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/14 20:32:53 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_rev_print(av[1]);
	write(1, "\n", 1);
	return (0);
}