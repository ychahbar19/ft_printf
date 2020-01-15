/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_modified_for_cs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 12:14:14 by asouat            #+#    #+#             */
/*   Updated: 2019/05/08 15:37:24 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*apply_option_to_cs(t_arg *t_arg_elem, char *str)
{
	char *tmp;

	if (t_arg_elem->options.soustract)
	{
		if (!(tmp = ft_strjoin(str, t_arg_elem->prefix)))
			return (NULL);
		free(str);
		str = tmp;
	}
	else
	{
		if (!(tmp = ft_strjoin(t_arg_elem->prefix, str)))
			return (NULL);
		free(str);
		str = tmp;
	}
	return (str);
}

char			*apply_precision_for_cs(t_arg *t_arg_elem, char *str)
{
	char *tmp;

	if (t_arg_elem->precision > 0)
	{
		if (!(tmp = apply_precision_for_s(t_arg_elem, str)))
			return (NULL);
		free(str);
		str = tmp;
	}
	else if (t_arg_elem->precision == -1)
	{
		if (!(tmp = ft_strdup("")))
			return (NULL);
		free(str);
		str = tmp;
	}
	return (str);
}

static char		*apply_modif(t_arg *t_arg_elem, char *arg, char *str)
{
	char *tmp;

	if (!(str = apply_precision_for_cs(t_arg_elem, str)))
		return (NULL);
	if (get_prefix(t_arg_elem, str) == -1)
		return (NULL);
	if (t_arg_elem->has_options && *t_arg_elem->prefix)
	{
		if (!(str = apply_option_to_cs(t_arg_elem, str)))
			return (NULL);
	}
	else if ((t_arg_elem->width_min > 1) && *t_arg_elem->prefix)
	{
		if (!(tmp = ft_strjoin(t_arg_elem->prefix, str)))
			return (NULL);
		free(str);
		str = tmp;
	}
	return (str);
}

static char		*arg_null(t_arg *t_arg_elem)
{
	char *str;

	str = t_arg_elem->arg;
	if (get_prefix(t_arg_elem, "") == -1)
		return (NULL);
	if (t_arg_elem->precision == -1)
	{
		if (!(str = ft_strdup(t_arg_elem->prefix)))
			return (NULL);
	}
	else
	{
		if (!(str = ft_strdup("(null)")))
			return (NULL);
		if (!(str = apply_modif(t_arg_elem, "", str)))
			return (NULL);
	}
	return (str);
}

char			*get_arg_modified_for_cs(t_arg *t_arg_elem)
{
	char	*arg;
	char	*str;

	if (ft_strcmp(t_arg_elem->flag, "l"))
	{
		arg = t_arg_elem->arg;
		if (arg == NULL)
		{
			if (!(str = arg_null(t_arg_elem)))
				return (NULL);
			return (str);
		}
		if (!(str = ft_strdup(arg)))
			return (NULL);
		if (!(str = apply_modif(t_arg_elem, arg, str)))
			return (NULL);
		if (*arg && (t_arg_elem->type == 'c') && !(t_arg_elem->precision))
			free(arg);
	}
	else
	{
		if (!(str = ft_strnew(0)))
			return (NULL);
	}
	return (str);
}
