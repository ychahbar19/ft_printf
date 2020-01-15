/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_oux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:42:20 by asouat            #+#    #+#             */
/*   Updated: 2019/04/27 10:12:55 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	apply_flag_h_hh(t_arg *t_arg_elem, va_list args, t_dioux *dioux)
{
	if (!(ft_strcmp(t_arg_elem->flag, "hh")))
	{
		if (!(dioux->hh_unb = (unsigned char *)malloc(sizeof(unsigned char))))
			return (-1);
		*dioux->hh_unb = (unsigned char)va_arg(args, int);
		if (!(t_arg_elem->arg = oux_to_str(t_arg_elem, *dioux->hh_unb, dioux)))
			return (-1);
	}
	if (!(ft_strcmp(t_arg_elem->flag, "h")))
	{
		if (!(dioux->h_unb = malloc(sizeof(unsigned short int))))
			return (-1);
		*dioux->h_unb = (unsigned short int)va_arg(args, int);
		if (!(t_arg_elem->arg = oux_to_str(t_arg_elem, *dioux->h_unb, dioux)))
			return (-1);
	}
	return (0);
}

static int	apply_flag_l_ll(t_arg *t_arg_elem, va_list args, t_dioux *dioux)
{
	if (!(ft_strcmp(t_arg_elem->flag, "l")))
	{
		if (!(dioux->l_unb = malloc(sizeof(unsigned long int))))
			return (-1);
		*dioux->l_unb = (unsigned long int)va_arg(args, long int);
		if (!(t_arg_elem->arg = oux_to_str(t_arg_elem, *dioux->l_unb, dioux)))
			return (-1);
	}
	if (!(ft_strcmp(t_arg_elem->flag, "ll")))
	{
		if (!(dioux->ll_unb = malloc(sizeof(unsigned long long int))))
			return (-1);
		*dioux->ll_unb = (unsigned long long int)va_arg(args, long long int);
		if (!(t_arg_elem->arg = oux_to_str(t_arg_elem, *dioux->ll_unb, dioux)))
			return (-1);
	}
	return (0);
}

int			get_arg_uox(t_arg *t_arg_elem, va_list args, t_dioux *dioux)
{
	if (!(ft_strcmp(t_arg_elem->flag, "NULL")))
	{
		if (!(dioux->unb = (unsigned int *)malloc(sizeof(unsigned int))))
			return (-1);
		*dioux->unb = (unsigned int)va_arg(args, int);
		if (!(t_arg_elem->arg = oux_to_str(t_arg_elem, *dioux->unb, dioux)))
			return (-1);
	}
	else if (apply_flag_h_hh(t_arg_elem, args, dioux) == -1)
		return (-1);
	else if (apply_flag_l_ll(t_arg_elem, args, dioux) == -1)
		return (-1);
	return (0);
}
