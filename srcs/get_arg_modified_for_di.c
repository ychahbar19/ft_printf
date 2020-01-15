/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_modified_for_di.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 12:26:32 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 12:27:36 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_modif(t_arg *arg_elem, char *arg, char *str)
{
	char *tmp;

	if ((arg_elem->precision > 0) && arg_elem->precision >= ft_strlen(arg))
	{
		if (!(tmp = apply_precision(arg_elem, str)))
			return (NULL);
		free(str);
		str = tmp;
	}
	if (arg_elem->has_options)
	{
		if (!(str = apply_option_to_di(arg_elem, str, arg)))
			return (NULL);
	}
	else if ((arg_elem->width_min > 1) && *arg_elem->prefix)
	{
		if (!(tmp = ft_strjoin(arg_elem->prefix, str)))
			return (NULL);
		if ((arg_elem->precision >= ft_strlen(str)) || !(arg_elem->precision))
			free(str);
		str = tmp;
	}
	return (str);
}

char		*get_arg_modified_for_di(t_arg *arg_elem, t_dioux *dioux)
{
	char	*str;
	char	*arg;

	if (!(arg = di_to_str(arg_elem, dioux)))
		return (NULL);
	if (get_prefix(arg_elem, arg) == -1)
		return (NULL);
	if (!(str = ft_strdup(arg)))
		return (NULL);
	if (!(str = apply_modif(arg_elem, arg, str)))
		return (NULL);
	if ((ft_strcmp(arg, str)) ||
		((arg_elem->has_options) && (arg_elem->precision <= 0)) ||
		((!(arg_elem->has_options)) && ((arg_elem->precision < 1))) ||
		(arg_elem->precision < ft_strlen(arg)))
		free(arg);
	return (str);
}
