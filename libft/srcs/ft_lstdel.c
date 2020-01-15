/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:55:15 by asouat            #+#    #+#             */
/*   Updated: 2018/10/12 17:36:53 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	if (!(alst) || !(del))
		return ;
	list = *alst;
	while (list)
	{
		del((list)->content, (list)->content_size);
		free(list);
		list = list->next;
	}
	*alst = NULL;
}
