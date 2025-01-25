/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:49:06 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/22 12:53:00 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_snake_to_camel(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '_')
		{
			str[i + 1] -= ('a' - 'A');
			i++;
			write(1, &str[i], 1);  
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_snake_to_camel(av[1]);
	write(1, "\n", 1);
	return (0);
}