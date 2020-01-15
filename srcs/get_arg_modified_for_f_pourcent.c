/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_modified_for_f_pourcent.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:40:38 by asouat            #+#    #+#             */
/*   Updated: 2019/05/08 15:39:15 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_arg_modified_for_f(t_arg *t_arg_elem)
{
	char	*str;
	char	*arg;
	char	*tmp;

	arg = t_arg_elem->arg;
	if (get_prefix(t_arg_elem, arg) == -1)
		return (NULL);
	if (!(str = ft_strdup(arg)))
		return (NULL);
	if (t_arg_elem->has_options)
	{
		if (!(str = apply_option_to_f(t_arg_elem, str, arg)))
			return (NULL);
	}
	else if ((t_arg_elem->width_min > 1) && *t_arg_elem->prefix)
	{
		if (!(tmp = ft_strjoin(t_arg_elem->prefix, str)))
			return (NULL);
		free(str);
		str = tmp;
	}
	free(arg);
	return (str);
}

char		*get_arg_modified_for_pourcent(t_arg *t_arg_elem)
{
	char *str;

	if (get_prefix(t_arg_elem, "%") == -1)
		return (NULL);
	if (t_arg_elem->options.soustract && *t_arg_elem->prefix)
	{
		if (!(str = ft_strjoin("%", t_arg_elem->prefix)))
			return (NULL);
	}
	else if (!t_arg_elem->options.soustract && *t_arg_elem->prefix)
	{
		if (!(str = ft_strjoin(t_arg_elem->prefix, "%")))
			return (NULL);
	}
	else
	{
		if (!(str = ft_strdup("%")))
			return (NULL);
	}
	return (str);
}
