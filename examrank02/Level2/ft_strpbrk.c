/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:08:28 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/22 13:48:23 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				return (char *)&s1[i];
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

int	main(void)
{
	char	*s1 = "geeksforgeeks";
	char	*s2 = "kite";
	char *p;

	p = ft_strpbrk(s1, s2);
	if (p)
		printf("ft_strpbrk: %c\n", *p);
	else
		printf("No matching character found\n");
	return (0);
}
