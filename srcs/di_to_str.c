/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:33:55 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 11:46:23 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*di_to_str_h_hh(t_arg *t_arg_elem, t_dioux *dioux)
{
	char *arg;

	if (!(ft_strcmp(t_arg_elem->flag, "h")))
	{
		dioux->h_nb = t_arg_elem->arg;
		if (!(arg = ft_itoa(*dioux->h_nb)))
			return (NULL);
	}
	if (!(ft_strcmp(t_arg_elem->flag, "hh")))
	{
		dioux->hh_nb = t_arg_elem->arg;
		if (!(arg = ft_itoa(*dioux->hh_nb)))
			return (NULL);
	}
	return (arg);
}

static char	*di_to_str_l_ll(t_arg *t_arg_elem, t_dioux *dioux)
{
	char *arg;

	if (!(ft_strcmp(t_arg_elem->flag, "l")))
	{
		dioux->l_nb = t_arg_elem->arg;
		if (!(arg = ft_litoa(*dioux->l_nb)))
			return (NULL);
	}
	if (!(ft_strcmp(t_arg_elem->flag, "ll")))
	{
		dioux->ll_nb = t_arg_elem->arg;
		if (!(arg = ft_lltoa(*dioux->ll_nb)))
			return (NULL);
	}
	return (arg);
}

char		*di_to_str(t_arg *t_arg_elem, t_dioux *dioux)
{
	char *arg;

	if (!(ft_strcmp(t_arg_elem->flag, "NULL")))
	{
		dioux->nb = t_arg_elem->arg;
		if (!(arg = ft_itoa(*dioux->nb)))
			return (NULL);
	}
	else if (!(arg = di_to_str_h_hh(t_arg_elem, dioux)))
		return (NULL);
	else if (!(arg = di_to_str_l_ll(t_arg_elem, dioux)))
		return (NULL);
	return (arg);
}
