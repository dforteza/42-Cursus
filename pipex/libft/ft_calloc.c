/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:43:06 by dforteza          #+#    #+#             */
/*   Updated: 2024/09/29 17:32:54 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (size != 0 && num > SIZE_MAX / size)
		return (NULL);
	ptr = (void *)malloc(num * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, num * size);
	return (ptr);
}
