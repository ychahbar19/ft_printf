/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option_to_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:49:40 by asouat            #+#    #+#             */
/*   Updated: 2019/04/27 15:49:45 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_zero_x(t_arg *t_arg_elem)
{
	char *zero_x;

	if (t_arg_elem->type == 'x')
		zero_x = "0x";
	else
		zero_x = "0X";
	return (zero_x);
}

static char	*apply_diese(t_arg *t_arg_elem, char *str, char *arg, char *zero_x)
{
	char *ptr;

	if (t_arg_elem->options.zero && (t_arg_elem->width_min > 1))
	{
		if (!(ptr = ft_strjoin3(zero_x, t_arg_elem->prefix, str)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else if (!t_arg_elem->options.soustract && (t_arg_elem->width_min > 1))
	{
		if (!(ptr = ft_strjoin3(t_arg_elem->prefix, zero_x, str)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else if (t_arg_elem->width_min > 1)
	{
		if (!(ptr = ft_strjoin3(zero_x, str, t_arg_elem->prefix)))
			return (NULL);
		free(str);
		str = ptr;
	}
	return (str);
}

static char	*apply_option_soustra_or_0(t_arg *t_arg_elem, char *str, char *arg)
{
	char *ptr;

	if (t_arg_elem->options.soustract && *t_arg_elem->prefix)
	{
		if (!(ptr = ft_strjoin(str, t_arg_elem->prefix)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else if (*t_arg_elem->prefix)
	{
		if (!(ptr = ft_strjoin(t_arg_elem->prefix, str)))
			return (NULL);
		free(str);
		str = ptr;
	}
	return (str);
}

char		*apply_option_to_x(t_arg *t_arg_elem, char *str, char *arg)
{
	char *ptr;
	char *zero_x;

	zero_x = get_zero_x(t_arg_elem);
	if (t_arg_elem->options.diese)
	{
		if (!(str = apply_diese(t_arg_elem, str, arg, zero_x)))
			return (NULL);
		if (t_arg_elem->width_min == 1)
		{
			if (!(ptr = ft_strjoin(zero_x, str)))
				return (NULL);
			free(str);
			str = ptr;
		}
	}
	else if (t_arg_elem->has_options && *t_arg_elem->prefix)
	{
		if (!(str = apply_option_soustra_or_0(t_arg_elem, str, arg)))
			return (NULL);
	}
	return (str);
}
