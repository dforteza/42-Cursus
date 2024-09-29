/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:48:24 by dforteza          #+#    #+#             */
/*   Updated: 2024/09/28 16:50:40 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	to_find_size;

	to_find_size = ft_strlen(to_find);
	i = 0;
	if (to_find_size == 0)
		return ((char *)&str[i]);
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j) < n && to_find[j] != '\0')
		{
			j++;
			if (j == to_find_size)
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
