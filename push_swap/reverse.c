/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:00:41 by dforteza          #+#    #+#             */
/*   Updated: 2025/05/27 00:09:20 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack **top)
{
	t_stack	*ex_top;
	t_stack	*new_bottom;
	t_stack	*ex_bottom;

	// 1- INICIALIZAR PUNTEROS AL TOPE ACTUAL
	ex_bottom = *top;
	new_bottom = *top;
	ex_top = *top;

	// 2- ENCONTRAR EL ÚLTIMO NODO (EX_BOTTOM)
	while (ex_bottom->next)
		ex_bottom = ex_bottom->next;

	// 3- ENCONTRAR EL NODO ANTERIOR AL ÚLTIMO (NEW_BOTTOM)
	while (new_bottom->next->next)
		new_bottom = new_bottom->next;

	// 4- ACTUALIZAR EL TOPE: EL ÚLTIMO NODO PASA A SER EL PRIMERO
	*top = ex_bottom;
	(*top)->next = ex_top;

	// 5- EL NUEVO ÚLTIMO NODO APUNTA A NULL
	new_bottom->next = NULL;
}

void	rotate(t_stack **top)
{
	t_stack	*ex_top;
	t_stack	*bottom;

	// 1- GUARDAR EL TOPE ACTUAL
	ex_top = *top;

	// 2- MOVER EL TOPE AL SIGUIENTE NODO
	*top = (*top)->next;

	// 3- ENCONTRAR EL NUEVO FINAL DE LA LISTA
	bottom = *top;
	while (bottom->next)
		bottom = bottom->next;

	// 4- EL ANTIGUO TOPE SE CONVIERTE EN EL NUEVO FINAL
	ex_top->next = NULL;
	bottom->next = ex_top;
}

void	rotate_move(t_stack **sa, t_stack **sb, char *choice)
{
	// 1- EJECUTAR ROTACIÓN SEGÚN LA OPERACIÓN SOLICITADA
	if (ft_strcmp(choice, "ra") == 0)
		rotate(sa);
	else if (ft_strcmp(choice, "rb") == 0)
		rotate(sb);
	else if (ft_strcmp(choice, "rr") == 0)
	{
		rotate(sa);
		rotate(sb);
	}
	else if (ft_strcmp(choice, "rra") == 0)
		reverse(sa);
	else if (ft_strcmp(choice, "rrb") == 0)
		reverse(sb);
	else if (ft_strcmp(choice, "rrr") == 0)
	{
		reverse(sa);
		reverse(sb);
	}

	// 2- IMPRIMIR LA OPERACIÓN REALIZADA
	ft_putstr(choice);
	ft_putstr("\n");
}