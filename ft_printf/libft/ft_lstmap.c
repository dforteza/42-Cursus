/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforteza <dforteza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:12:28 by dforteza          #+#    #+#             */
/*   Updated: 2024/09/29 18:41:35 by dforteza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*mapped_list;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	mapped_list = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			ft_lstclear(&mapped_list, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&mapped_list, tmp);
		lst = lst->next;
	}
	return (mapped_list);
}
