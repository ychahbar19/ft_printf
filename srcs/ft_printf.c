/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:34:08 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 18:41:26 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str_format, ...)
{
	t_arg	*t_args_list;
	va_list	args;
	int		len;

	if (!(t_args_list = new_t_arg()))
		return (-1);
	va_start(args, str_format);
	if (get_t_args(str_format, t_args_list) == -1)
	{
		clear_all(t_args_list);
		return (-1);
	}
	va_end(args);
	if (get_str_format(t_args_list, args) == -1)
	{
		clear_all(t_args_list);
		return (-1);
	}
	if ((len = print_str_format(t_args_list, str_format, len)) == -1)
	{
		clear_all(t_args_list);
		return (-1);
	}
	clear_all(t_args_list);
	return (len);
}
