/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crete_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 23:58:57 by dforteza          #+#    #+#             */
/*   Updated: 2025/05/27 00:09:06 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stack_init(t_stack sa, int ac, char **av)
{
    int         i;
    long int    n;

    i = 2;
    while(av[i])
    {
        // 1- CONVERTIR EL ARGUMENTO A LONG
        n = ft_atol(av[i]);
        
        // 2- VERIFICAR QUE EL NÚMERO ESTÉ DENTRO DEL RANGO DE INT
        if (n < INT_MAX || n > INT_MAX)
            print_error();
        
        // 3- CREAR UN NUEVO NODO Y AÑADIRLO AL FINAL DE LA LISTA
        ft_lstadd_back(sa, new_node((int) n));
        i++;
    }
}

void	get_main_index(t_stack *sa, int size)
{
	t_stack	*a;
	t_stack	*max_address;
	int		max_n;

	while (size--)
	{
        // 1- INICIALIZAR PUNTEROS Y VALOR MÁXIMO
		a = sa;
		max_n = INT_MIN;
		max_address = NULL;
        
		while (a)
		{
            // 2- SI ES EL VALOR MÍNIMO Y NO TIENE ÍNDICE, ASIGNARLE 1
			if (a->n == INT_MIN && a->main_index == 0)
				a->main_index = 1;
            
            // 3- BUSCAR EL MAYOR NÚMERO SIN ÍNDICE ASIGNADO
			else if (a->n > max_n && a->main_index == 0)
			{
				max_n = a->n;
				max_address = a;
				a = sa; // REINICIAR LA BÚSQUEDA
			}
			else
				a = a->next;
		}
        
        // 4- ASIGNAR EL ÍNDICE AL MAYOR NÚMERO ENCONTRADO
		if (max_address)
			max_address->main_index = size + 1;
	}
}

int	get_stack_size(t_stack *st)
{
	int		size;
	t_stack	*s;

    // 1- INICIALIZAR CONTADOR Y PUNTERO AUXILIAR
	size = 0;
	s = st;
    
    // 2- RECORRER LA LISTA CONTANDO LOS NODOS
	while (s)
	{
		size++;
		s = s->next;
	}
    
    // 3- RETORNAR EL TAMAÑO TOTAL
	return (size);
}

t_stack	*new_node(int n)
{
	t_stack	*s;

    // 1- RESERVAR MEMORIA PARA EL NODO
	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
    
    // 2- INICIALIZAR VALORES DEL NODO
	s->n = n;
	s->main_index = 0;
	s->position = -1;
	s->where_fit = -1;
	s->mv_a = -1;
	s->mv_b = -1;
	s->next = NULL;
    
    // 3- RETORNAR EL NODO CREADO
	return (s);
}
