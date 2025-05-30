/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:51:18 by dforteza          #+#    #+#             */
/*   Updated: 2025/05/27 11:26:46 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_sorted(t_stack *st)
{
    t_stack *current;

    if (!st || !st->next)
        return (1);
    current = st;
    while (current->next)
    {
        if (current->n > current->next->n)
            return (0);
        current = current->next;
    }
    return (1);
}

void push_swap(t_stack **sa, t_stack **sb)
{
    if (size == 2 && !ft_is_sorted(*sa))
        swap(sa)
    else if (size == 3)
        small_sort(sa);
    else if (size > 3 && !ft_is_sorted(*sa))
        index_sort(sa, sb);
}

void    main(int ac, char **av)
{
    t_stack *sa;
    t_stack *sb;
    int     size;
    
    // 1- INIT STACKS
    sa = NULL;
    sb = NULL;
    // 2- PARSE ARGS
    if (ac == 1)
        return ;
    // 3- Init SA
    stack_init(&sa, ac, av);
    size = s_size(sa);
    // 4- PUSH SWAP
    push_swap(&sa, &sb, size);
    // 5- FREE STACKS
    free_stack(&sa);
    free_stack(&sb);
    return (0);
}
