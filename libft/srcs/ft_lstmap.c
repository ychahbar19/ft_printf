/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:30:12 by asouat            #+#    #+#             */
/*   Updated: 2018/10/12 17:11:35 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*list;

	if (!(lst) || !(f))
		return (NULL);
	list = f(lst);
	new_list = list;
	lst = lst->next;
	while (lst)
	{
		if (!(list->next = f(lst)))
			return (NULL);
		list = list->next;
		lst = lst->next;
	}
	return (new_list);
}
