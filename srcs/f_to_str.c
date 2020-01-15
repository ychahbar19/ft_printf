/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_to_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:19:21 by asouat            #+#    #+#             */
/*   Updated: 2019/05/08 15:23:05 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_decimal_str(long double d, char *str_decimal, int len)
{
	int		nb;
	int		report;
	char	*tmp1;
	int		i;

	i = 0;
	report = 0;
	while (i < len)
	{
		d = d * 10.0;
		if (!(tmp1 = ft_itoa((int)d % 10)))
			return (-1);
		if (((int)d % 10) == 0)
			str_decimal[i] = '0';
		else
			str_decimal[i] = *tmp1;
		d -= (int)d / 10 * 10;
		i++;
		free(tmp1);
	}
	nb = ((int)(d * 10)) % 10;
	if (nb >= 5 && nb <= 9)
		report = ft_round_num(str_decimal, len, report);
	return (report);
}

static char	*apply_report(char *s_int)
{
	if (s_int[0] == '-')
	{
		if (!(s_int = ft_strjoin("-1", s_int + 1)))
			return (NULL);
	}
	else
	{
		if (!(s_int = ft_strjoin("1", s_int)))
			return (NULL);
	}
	return (s_int);
}

static char	*get_decimal(t_arg *t_arg_elem, long double decimal, char **s_int)
{
	int		len;
	char	*str_decimal;
	int		report;

	if (decimal < 0)
		decimal = decimal * -1;
	if (t_arg_elem->precision > 0)
		len = t_arg_elem->precision;
	else
		len = 6;
	if (!(str_decimal = ft_strnew(len)))
		return (NULL);
	if ((report = get_decimal_str(decimal, str_decimal, len)) == -1)
		return (NULL);
	if (report == 1)
	{
		len = ft_strlen(*s_int);
		report = ft_round_num(*s_int, len, report);
		if (report == 1)
		{
			if (!(*s_int = apply_report(*s_int)))
				return (NULL);
		}
	}
	return (str_decimal);
}

static char	*apply_precision_neg(t_arg *t_arg_elem, char *s_decim, char *s_int)
{
	char	*str;
	int		report;
	int		len;

	if ((s_decim[0] >= 53) && (s_decim[0] <= 57))
	{
		report = 1;
		len = ft_strlen(s_int);
		report = ft_round_num(s_int, len, report);
		if (report == 1)
		{
			if (!(s_int = apply_report(s_int)))
				return (NULL);
		}
	}
	if (!(str = apply_option_diese_to_f(t_arg_elem, s_int)))
		return (NULL);
	return (str);
}

char		*f_to_str(t_arg *t_arg_elem, long double decimal, char *s_int)
{
	char	*str;
	char	*str_decimal;

	if (!(str_decimal = get_decimal(t_arg_elem, decimal, &s_int)))
		return (NULL);
	if (t_arg_elem->precision != -1)
	{
		if (!(str = ft_strjoin3(s_int, ".", str_decimal)))
			return (NULL);
	}
	else
	{
		if (!(str = apply_precision_neg(t_arg_elem, str_decimal, s_int)))
			return (NULL);
	}
	free(str_decimal);
	return (str);
}
