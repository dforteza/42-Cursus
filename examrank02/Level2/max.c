/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:13:46 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/21 20:18:58 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int	i;
	int	max = 0;

	if (len == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		// printf("%d : %d /// %d\n", i, tab[i], max);
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int main(void)
{
	int arr[] = {1, 3, 7, 2, 5};
	unsigned int len = sizeof(arr) / sizeof(arr[0]);
	int result = max(arr, len);

	printf("The maximum value is: %d\n", result);
	return 0;
}