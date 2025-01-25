/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:57:28 by dforteza          #+#    #+#             */
/*   Updated: 2025/01/24 20:05:01 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int hcf(unsigned int a, unsigned int b)
{
    unsigned int temp;
    
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
        printf("%u // %u\n", b, a);
    }
    return (a);
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int n;
    
    if (a == 0 || b == 0)
        return (0);
    // Función auxiliar para calcular el HCF (o GCD)
    n = hcf(a, b);
    // Devuelve el LCM usando la fórmula
    return ((a / n) * b);
}

int main()
{
    printf("LCM of 12 and 18: %u\n", lcm(12, 18)); // Expected: 36
    printf("LCM of 0 and 18: %u\n", lcm(0, 18));  // Expected: 0
    printf("LCM of 7 and 5: %u\n", lcm(7, 5));   // Expected: 35
    return (0);
}

