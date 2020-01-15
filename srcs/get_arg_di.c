/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:34:47 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 11:58:47 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	apply_flag_h_hh(t_arg *t_arg_elem, va_list args, t_dioux *dioux)
{
	if (!(ft_strcmp(t_arg_elem->flag, "hh")))
	{
		if (!(dioux->hh_nb = (char *)malloc(sizeof(char))))
			return (-1);
		*dioux->hh_nb = (char)va_arg(args, int);
		t_arg_elem->arg = dioux->hh_nb;
	}
	if (!(ft_strcmp(t_arg_elem->flag, "h")))
	{
		if (!(dioux->h_nb = (short int *)malloc(sizeof(short int))))
			return (-1);
		*dioux->h_nb = (short int)va_arg(args, int);
		t_arg_elem->arg = dioux->h_nb;
	}
	return (0);
}

static int	apply_flag_l_ll(t_arg *t_arg_elem, va_list args, t_dioux *dioux)
{
	if (!(ft_strcmp(t_arg_elem->flag, "l")))
	{
		if (!(dioux->l_nb = (long int *)malloc(sizeof(long int))))
			return (-1);
		*dioux->l_nb = (long int)va_arg(args, long int);
		t_arg_elem->arg = dioux->l_nb;
	}
	if (!(ft_strcmp(t_arg_elem->flag, "ll")))
	{
		if (!(dioux->ll_nb = (long long int *)malloc(sizeof(long long int))))
			return (-1);
		*dioux->ll_nb = (long long int)va_arg(args, long long int);
		t_arg_elem->arg = dioux->ll_nb;
	}
	return (0);
}

int			get_arg_di(t_arg *t_arg_elem, va_list args, t_dioux *dioux)
{
	if (!(ft_strcmp(t_arg_elem->flag, "NULL")))
	{
		if (!(dioux->nb = (int *)malloc(sizeof(int))))
			return (-1);
		*dioux->nb = va_arg(args, int);
		t_arg_elem->arg = dioux->nb;
	}
	else if (apply_flag_h_hh(t_arg_elem, args, dioux) == -1)
		return (-1);
	else if (apply_flag_l_ll(t_arg_elem, args, dioux) == -1)
		return (-1);
	return (0);
}
