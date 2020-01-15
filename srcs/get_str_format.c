/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:50:49 by asouat            #+#    #+#             */
/*   Updated: 2019/05/08 15:45:08 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_priorite_option(t_arg *t_arg_elem)
{
	if (t_arg_elem->width_min == 1)
	{
		t_arg_elem->options.zero = 0;
		t_arg_elem->options.soustract = 0;
	}
	if (t_arg_elem->options.soustract)
	{
		if (t_arg_elem->options.plus)
			t_arg_elem->options.space = 0;
		t_arg_elem->options.zero = 0;
	}
	if (t_arg_elem->options.plus && t_arg_elem->options.zero)
		t_arg_elem->options.space = 0;
	if (t_arg_elem->precision > 0 && !(ft_strchr("f", t_arg_elem->type)))
	{
		if (t_arg_elem->type != '%')
			t_arg_elem->options.zero = 0;
	}
	if ((t_arg_elem->width_min > 1) && ft_strchr("diouxX", t_arg_elem->type) &&
		(t_arg_elem->precision == -1) && ft_strcmp("0", t_arg_elem->arg))
	{
		t_arg_elem->options.zero = 0;
		if (t_arg_elem->options.diese)
			t_arg_elem->precision = 0;
	}
}

int				get_str_format(t_arg *t_args_list, va_list args)
{
	t_dioux	*dioux;
	t_arg	*arg_elem;

	if (!(dioux = (t_dioux *)malloc(sizeof(t_dioux))))
		return (-1);
	arg_elem = t_args_list;
	while (arg_elem->next)
	{
		if (get_arg_for_t_arg(arg_elem, args, dioux) == -1)
		{
			free(dioux);
			return (-1);
		}
		get_priorite_option(arg_elem);
		if (get_arg_modified(arg_elem, dioux) == -1)
		{
			free(dioux);
			return (-1);
		}
		arg_elem = arg_elem->next;
	}
	if (t_args_list->type && ft_strchr("diouxX", t_args_list->type))
		clear_dioux(t_args_list, dioux);
	free(dioux);
	return (0);
}
