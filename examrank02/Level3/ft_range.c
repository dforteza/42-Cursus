/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:47:53 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/23 15:07:55 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int	i;
	int	size;
	int	*arr;

	if (start > end)
		return (NULL);
	
	size = end - start + 1;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	
	i = 0;
	while (i < size)
	{
		arr[i] = start;
		start++;
		i++;
	}
	return (arr);
}

int	main(void)
{
	int *arr;
	int	i;

	arr = ft_range(0 , 4);
	if (!arr)
	{
		printf("Error: rango inválido o memoria no asignada.\n");
		return (1);
	}	
	
	i = 0;
	while (i <= 4)
	{
		printf("%d ", *(arr + i));
		i++;
	}
	printf("\n");
    free(arr); 
	return (0);
}