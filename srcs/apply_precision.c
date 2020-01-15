/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:33:36 by asouat            #+#    #+#             */
/*   Updated: 2019/05/08 15:16:12 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*apply_precision_for_s(t_arg *t_arg_elem, char *arg)
{
	char	*str;

	if (!(str = ft_strsub(arg, 0, t_arg_elem->precision)))
		return (NULL);
	return (str);
}

static int	get_precision_len(t_arg *t_arg_elem, char *arg)
{
	int		precision_len;

	precision_len = t_arg_elem->precision - ft_strlen(arg);
	if (arg[0] == '-')
		precision_len++;
	if (t_arg_elem->options.diese && t_arg_elem->type == 'o' &&
			ft_strcmp("0", t_arg_elem->arg))
		precision_len--;
	return (precision_len);
}

char		*apply_precision(t_arg *t_arg_elem, char *arg)
{
	int		precision_len;
	char	*str;
	char	*precision;
	int		i;

	precision_len = get_precision_len(t_arg_elem, arg);
	if (precision_len < 0)
		return (arg);
	if (!(precision = ft_strnew(precision_len)))
		return (NULL);
	i = 0;
	if (arg[0] == '-')
	{
		precision[i++] = '-';
		arg[0] = '0';
	}
	while (i < precision_len)
		precision[i++] = '0';
	if (!(str = ft_strjoin(precision, arg)))
		return (NULL);
	free(precision);
	return (str);
}
