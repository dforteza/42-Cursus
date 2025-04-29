/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:28:39 by dforteza          #+#    #+#             */
/*   Updated: 2025/04/29 16:29:07 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_stack	*new_node(int n)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->n = n;
	s->next = NULL;
	return (s);
}

static void	add_at_end(t_stack **st, t_stack *new)
{
	t_stack	*s;

	if (!new)
		return ;
	if (!*st)
		*st = new;
	else
	{
		s = *st;
		while (s->next)
			s = s->next;
		s->next = new;
	}
}

t_stack	*create_stack(int ac, char **av)
{
	t_stack		*sa;
	long int	n;
	int			i;

	sa = NULL;
	n = 0;
	i = 1;
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			print_error_and_exit(&sa, NULL);
		if (i == 1)
			sa = new_node((int)n);
		else
			add_at_end(&sa, new_node((int)n));
		i++;
	}
	return (sa);
}
