/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:06:01 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 14:09:16 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	clear_di(t_arg *t_arg_elem, t_dioux *dioux)
{
	if (!(ft_strcmp(t_arg_elem->flag, "NULL")))
		free(dioux->nb);
	if (!(ft_strcmp(t_arg_elem->flag, "l")))
		free(dioux->l_nb);
	if (!(ft_strcmp(t_arg_elem->flag, "ll")))
		free(dioux->ll_nb);
	if (!(ft_strcmp(t_arg_elem->flag, "h")))
		free(dioux->h_nb);
	if (!(ft_strcmp(t_arg_elem->flag, "hh")))
		free(dioux->hh_nb);
}

void		clear_dioux(t_arg *t_arg_elem, t_dioux *dioux)
{
	if (ft_strchr("di", t_arg_elem->type))
		clear_di(t_arg_elem, dioux);
	if (ft_strchr("ouxX", t_arg_elem->type))
	{
		if (!(ft_strcmp(t_arg_elem->flag, "NULL")))
			free(dioux->unb);
		if (!(ft_strcmp(t_arg_elem->flag, "l")))
			free(dioux->l_unb);
		if (!(ft_strcmp(t_arg_elem->flag, "ll")))
			free(dioux->ll_unb);
		if (!(ft_strcmp(t_arg_elem->flag, "h")))
			free(dioux->h_unb);
		if (!(ft_strcmp(t_arg_elem->flag, "hh")))
			free(dioux->hh_unb);
	}
}

void		clear_all(t_arg *args_list)
{
	t_arg *tmp1;
	t_arg *tmp2;

	tmp1 = args_list;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		free(tmp1->prefix);
		free(tmp1->arg_modified);
		free(tmp1->settings);
		free(tmp1);
		tmp1 = tmp2;
	}
}

void		free_wchar_t(wchar_t **ws)
{
	int j;

	j = 0;
	while (ws[j])
	{
		free(ws[j]);
		j++;
	}
	free(ws);
}
