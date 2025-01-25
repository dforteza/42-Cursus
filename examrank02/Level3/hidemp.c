/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidemp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:30:07 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/23 20:43:57 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
} 

int ft_hidemp(char *s1, char *s2)
{
    int i;
    int j;
    int cont;

    cont = 0;
    i = 0;
    j = 0;
    while (s1[i])
    {
        while (s2[j])
        {
            if (s1[i] == s2[j])
            {
                cont++;
                break ;
            }
            j++;
        }
        i++;
    }
    if (cont == ft_strlen(s1))
        return (1);
    return (0);
}

#include <unistd.h> 

int main(int ac, char **av)
{
    int n;
    
    if (ac == 3)
    {
        n = ft_hidemp(av[1], av[2]);
        if (n)
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
    write(1, "\n", 1);
    return (0);
}