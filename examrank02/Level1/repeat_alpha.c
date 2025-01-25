/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:58:21 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/14 20:11:23 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_repeat_alpha(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			j = str[i] - 'a' + 1;
			while (j > 0)
			{
				write(1, &str[i], 1);
				j--;
			}
		}
		else if ((str[i] >= 'A' && str[i] <= 'Z'))
		{
			j = str[i] - 'A' + 1;
			while (j > 0)
			{
				write(1, &str[i], 1);
				j--;
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_repeat_alpha(av[1]);
	write(1, "\n", 1);
	return (0);
}