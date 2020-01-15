/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_to_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:49:04 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 15:49:45 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*u_to_str_h_hh(t_arg *t_arg_elem, t_dioux *dioux)
{
	char *arg;

	if (!(ft_strcmp(t_arg_elem->flag, "hh")))
	{
		if (!(arg = ft_uitoa(*dioux->hh_unb)))
			return (NULL);
	}
	else if (!(ft_strcmp(t_arg_elem->flag, "h")))
	{
		if (!(arg = ft_uitoa(*dioux->h_unb)))
			return (NULL);
	}
	return (arg);
}

static char	*u_to_str_l_ll(t_arg *t_arg_elem, t_dioux *dioux)
{
	char *arg;

	if (!(ft_strcmp(t_arg_elem->flag, "ll")))
	{
		if (!(arg = ft_lluitoa(*dioux->ll_unb)))
			return (NULL);
	}
	else if (!(ft_strcmp(t_arg_elem->flag, "l")))
	{
		if (!(arg = ft_luitoa(*dioux->l_unb)))
			return (NULL);
	}
	return (arg);
}

char		*u_to_str(t_arg *t_arg_elem, t_dioux *dioux)
{
	char *arg;

	if (!(ft_strcmp(t_arg_elem->flag, "NULL")))
	{
		if (!(arg = ft_uitoa(*dioux->unb)))
			return (NULL);
	}
	else if (!(arg = u_to_str_h_hh(t_arg_elem, dioux)))
		return (NULL);
	else if (!(arg = u_to_str_l_ll(t_arg_elem, dioux)))
		return (NULL);
	return (arg);
}
