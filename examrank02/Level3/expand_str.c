/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:29:50 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/23 14:42:42 by dforteza         ###   ########.fr       */
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
void ft_expand_str(char *str)
{
	int	i;
	int	flg;

	flg = 0;
	i = 0;
	while (ft_is_space(str[i]))
		i++;
	while (str[i])
	{
		if (ft_is_space(str[i]))
			flg = 1;
		else
		{
			if (flg)
				write(1, "   ", 3);
			flg = 0;
			write(1, &str[i], 1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_expand_str(av[1]);
	write(1, "\n", 1);
	return (0);
}