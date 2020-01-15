/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:59:35 by asouat            #+#    #+#             */
/*   Updated: 2019/05/16 14:38:21 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_str_entier(t_arg *t_arg_elem, long double arg)
{
	unsigned long	data[1];
	char			*str_entier;
	double			d;
	int				sign;

	d = arg;
	sign = 0;
	ft_memcpy(data, &d, sizeof(data));
	if ((data[0] >> 63) == 1)
		sign = 1;
	if (arg == 0.0 && sign)
	{
		if (!(str_entier = ft_strdup("-0")))
			return (NULL);
	}
	else
	{
		if (!(str_entier = ft_lltoa((long long)arg)))
			return (NULL);
	}
	return (str_entier);
}

int			get_arg_f(t_arg *t_arg_elem, va_list args)
{
	long double	arg;
	long double	decimal;
	char		*str_entier;
	char		*str;

	if (!(ft_strcmp(t_arg_elem->flag, "L")))
		arg = va_arg(args, long double);
	else
		arg = va_arg(args, double);
	if (((long long)arg > LONG_MIN) && ((long long)arg < LONG_MAX))
	{
		if (!(str_entier = get_str_entier(t_arg_elem, arg)))
			return (-1);
		decimal = (long double)(arg - (long long)arg);
	}
	else
	{
		decimal = 0.0;
		if (!(str_entier = ft_strdup("0")))
			return (-1);
	}
	if (!(t_arg_elem->arg = f_to_str(t_arg_elem, decimal, str_entier)))
		return (-1);
	free(str_entier);
	return (0);
}
