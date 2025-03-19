/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:50:53 by dforteza          #+#    #+#             */
/*   Updated: 2024/09/29 13:42:17 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*str)
	{
		if (*str == (unsigned char)c)
			last_occurrence = (char *)str;
		str++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str);
	return (last_occurrence);
}
