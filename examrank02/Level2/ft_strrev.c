/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:27:25 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/20 13:49:12 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char    *ft_strrev(char *str)
{
    int     len;
    int		i;
    char	temp;

    if (!str)
        return (NULL);
    len = ft_strlen(str);
    i = 0;
    while (i < len / 2)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
        i++;
    }
    return (str);
}
#include <stdio.h>

int	main(void)
{
    char str[] = "HolaMundo";
    printf("%s\n", ft_strrev(str));
}