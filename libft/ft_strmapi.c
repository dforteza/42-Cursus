/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:59:24 by dforteza          #+#    #+#             */
/*   Updated: 2024/09/28 20:41:45 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (str == NULL || f == NULL)
		return (NULL);
	result = (char *)malloc((ft_strlen(str) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		result[i] = (*f)(i, str[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
