/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option_to_o.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:05:45 by asouat            #+#    #+#             */
/*   Updated: 2019/04/25 17:06:42 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_option_diese(t_arg *t_arg_elem, char *str, char *arg)
{
	char *ptr;

	if (t_arg_elem->options.zero && (t_arg_elem->width_min > 1))
	{
		if (!(ptr = ft_strjoin3("0", t_arg_elem->prefix, arg)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else if (!t_arg_elem->options.soustract && (t_arg_elem->width_min > 1))
	{
		if (!(ptr = ft_strjoin3(t_arg_elem->prefix, "0", arg)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else if (t_arg_elem->width_min > 1)
	{
		if (!(ptr = ft_strjoin3("0", arg, t_arg_elem->prefix)))
			return (NULL);
		free(str);
		str = ptr;
	}
	return (str);
}

static char	*apply_option_soustract(t_arg *t_arg_elem, char *str, char *arg)
{
	char *ptr;

	if (!(ptr = ft_strjoin(str, t_arg_elem->prefix)))
		return (NULL);
	free(str);
	str = ptr;
	return (str);
}

static char	*apply_option_zero(t_arg *t_arg_elem, char *str, char *arg)
{
	char *ptr;

	if (!(ptr = ft_strjoin(t_arg_elem->prefix, str)))
		return (NULL);
	free(str);
	str = ptr;
	return (str);
}

char		*apply_option_to_o(t_arg *t_arg_elem, char *str, char *arg)
{
	char *ptr;

	if (t_arg_elem->options.diese)
	{
		if (!(str = apply_option_diese(t_arg_elem, str, arg)))
			return (NULL);
		if (t_arg_elem->width_min == 1)
		{
			if (!(ptr = ft_strjoin("0", str)))
				return (NULL);
			free(str);
			str = ptr;
		}
	}
	else if (t_arg_elem->options.soustract && *t_arg_elem->prefix)
	{
		if (!(str = apply_option_soustract(t_arg_elem, str, arg)))
			return (NULL);
	}
	else if (*t_arg_elem->prefix)
	{
		if (!(str = apply_option_zero(t_arg_elem, str, arg)))
			return (NULL);
	}
	return (str);
}
