/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_modified_for_oux.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 12:27:59 by asouat            #+#    #+#             */
/*   Updated: 2019/05/08 15:42:21 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*apply_option_to_oux(t_arg *t_arg_elem, char *str, char *arg)
{
	if (!(ft_strcmp(arg, "0")))
		t_arg_elem->options.diese = 0;
	if (t_arg_elem->type == 'u')
	{
		if (!(str = apply_option_to_u(t_arg_elem, str, arg)))
			return (NULL);
	}
	if (t_arg_elem->type == 'o')
	{
		if (!(str = apply_option_to_o(t_arg_elem, str, arg)))
			return (NULL);
	}
	if (ft_strchr("xX", t_arg_elem->type))
	{
		if (!(str = apply_option_to_x(t_arg_elem, str, arg)))
			return (NULL);
	}
	return (str);
}

static char		*apply_modif(t_arg *t_arg_elem, char *arg, char *str)
{
	char *tmp;

	if (t_arg_elem->precision > 0)
	{
		if (!(tmp = apply_precision(t_arg_elem, arg)))
			return (NULL);
		free(str);
		str = tmp;
	}
	if (t_arg_elem->has_options)
	{
		if (!(str = apply_option_to_oux(t_arg_elem, str, arg)))
			return (NULL);
	}
	else if ((t_arg_elem->width_min > 1) && *t_arg_elem->prefix)
	{
		if (!(tmp = ft_strjoin(t_arg_elem->prefix, str)))
			return (NULL);
		if ((t_arg_elem->precision - ft_strlen(arg)) > 0)
			free(str);
		str = tmp;
	}
	return (str);
}

char			*get_arg_modified_for_oux(t_arg *t_arg_elem)
{
	char	*tmp;
	char	*arg;
	char	*str;
	int		arg_len;

	arg = t_arg_elem->arg;
	arg_len = ft_strlen(arg);
	if (get_prefix(t_arg_elem, arg) == -1)
		return (NULL);
	if (!(str = ft_strdup(arg)))
		return (NULL);
	if (!(str = apply_modif(t_arg_elem, arg, str)))
		return (NULL);
	if ((t_arg_elem->precision == 0) || ((t_arg_elem->precision == -1) &&
		(t_arg_elem->width_min == 1)) || ((!t_arg_elem->precision) &&
		(t_arg_elem->width_min > 1)) || ((t_arg_elem->precision > arg_len) &&
		(t_arg_elem->width_min > 1)) || ((t_arg_elem->precision == -1) &&
		(t_arg_elem->width_min > 1)) || (t_arg_elem->precision > arg_len))
		free(arg);
	return (str);
}
