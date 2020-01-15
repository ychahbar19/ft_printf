/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:35:23 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 13:58:08 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	reduce_len(t_arg *t_arg_elem, char *arg, int prefix_len)
{
	if (t_arg_elem->type == 'o' && t_arg_elem->options.diese &&
	ft_strcmp("0", t_arg_elem->arg))
		prefix_len--;
	if ((!((ft_strchr("ouxX", t_arg_elem->type))) && (t_arg_elem->options.plus)
	&& arg[0] != '-') || ((t_arg_elem->precision > 0) &&
	t_arg_elem->has_options && arg[0] == '-'))
		prefix_len--;
	if (((ft_strchr("o", t_arg_elem->type)) && t_arg_elem->options.diese &&
		t_arg_elem->precision > 0 && ft_strcmp("0", t_arg_elem->arg)) ||
		(ft_strchr("ouxX", t_arg_elem->type) && t_arg_elem->options.space))
		prefix_len++;
	if ((t_arg_elem->options.soustract || t_arg_elem->options.zero) &&
			arg[0] != '-' && t_arg_elem->options.space)
		prefix_len--;
	if ((ft_strchr("xX", t_arg_elem->type) && t_arg_elem->options.diese &&
			ft_strcmp("0", t_arg_elem->arg)) || (t_arg_elem->type == 'p'))
		prefix_len -= 2;
	if (t_arg_elem->options.space && t_arg_elem->width_min == 1)
		prefix_len = 0;
	if (t_arg_elem->type == 'c' && !(*arg))
		prefix_len = t_arg_elem->width_min - 1;
	if ((t_arg_elem->precision > 0) && (t_arg_elem->width_min > 1) &&
			arg[0] == '-' && t_arg_elem->precision > ft_strlen(arg))
		prefix_len--;
	return (prefix_len);
}

static int	get_prefix_len(t_arg *t_arg_elem, char *arg)
{
	int	prefix_len;
	int	arg_len;

	arg_len = ft_strlen(arg);
	if ((t_arg_elem->width_min <= arg_len))
		prefix_len = 0;
	else if ((t_arg_elem->precision == -1) && (t_arg_elem->width_min > 1) &&
			(t_arg_elem->type != '%') && (!(ft_strcmp(arg, "0"))))
		prefix_len = t_arg_elem->width_min;
	else if (!t_arg_elem->precision || (t_arg_elem->precision < arg_len))
		prefix_len = t_arg_elem->width_min - arg_len;
	else if ((t_arg_elem->type == 's') && (t_arg_elem->precision > arg_len) &&
			(t_arg_elem->width_min > 1))
		prefix_len = t_arg_elem->width_min - arg_len;
	else if (!(*arg) && t_arg_elem->width_min > 1)
		prefix_len = t_arg_elem->width_min;
	else if (((t_arg_elem->precision > 1) || (t_arg_elem->precision == -1)) &&
			(t_arg_elem->width_min > 1) && (t_arg_elem->type == '%'))
		prefix_len = t_arg_elem->width_min - 1;
	else if (!(*arg))
		prefix_len = 0;
	else
		prefix_len = t_arg_elem->width_min - t_arg_elem->precision;
	prefix_len = reduce_len(t_arg_elem, arg, prefix_len);
	return (prefix_len);
}

int			get_prefix(t_arg *t_arg_elem, char *arg)
{
	int		prefix_len;
	char	*ptr;
	int		i;
	char	c;

	if (arg)
		prefix_len = get_prefix_len(t_arg_elem, arg);
	else
		prefix_len = -1;
	c = ' ';
	if ((prefix_len < 0))
		return (0);
	if ((prefix_len >= 0) && !(ptr = ft_strnew(prefix_len)))
		return (-1);
	free(t_arg_elem->prefix);
	t_arg_elem->prefix = ptr;
	if (t_arg_elem->options.zero)
		c = '0';
	i = 0;
	while (i < prefix_len)
	{
		t_arg_elem->prefix[i] = c;
		i++;
	}
	return (1);
}
