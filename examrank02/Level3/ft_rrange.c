/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:08:53 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/23 15:22:03 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
    int	size;
    int	*arr;
    int	i;

    size = (end >= start) ? end - start + 1 : start - end + 1;
    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return (NULL);
    
    i = 0;
    while (i < size)
    {
        arr[i] = end;
        if (end > start)
            end--;
        else
            end++;
        i++;
    }
    return (arr);
}

int	main(void)
{
    int	i;
    int *arr;
    int	start = 1;
    int	end = 5;
    int	size = (end >= start) ? end - start + 1 : start - end + 1;

    arr = ft_rrange(start, end);
    if (!arr)
    {
        printf("Error: rango inválido o memoria no asignada.\n");
        return (1);
    }
    i = 0;
    while (i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    free(arr);
    return (0);
}