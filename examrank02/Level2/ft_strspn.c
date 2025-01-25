/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:48:19 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/20 12:06:20 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;
	size_t	cont;

	i = 0;
	while (s[i])
	{
		cont = 0;
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
			{
				cont++;
				break ;
			}
			j++;
		}
		if (cont < 1)
			break ;
		i++;
	}
	return (i);
}