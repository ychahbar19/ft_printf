/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option_to_di.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:33:14 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 10:26:15 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_last_modif(t_arg *t_arg_elem, char *str)
{
	char *ptr;

	if (t_arg_elem->options.soustract && !(t_arg_elem->options.space) &&
			*t_arg_elem->prefix)
	{
		if (!(ptr = ft_strjoin(str, t_arg_elem->prefix)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else if (!(t_arg_elem->options.soustract) && !(t_arg_elem->options.zero) &&
			*t_arg_elem->prefix)
	{
		if (!(ptr = ft_strjoin(t_arg_elem->prefix, str)))
			return (NULL);
		free(str);
		str = ptr;
	}
	return (str);
}

char		*apply_option_to_di(t_arg *t_arg_elem, char *str, char *arg)
{
	if (arg[0] == '-')
		t_arg_elem->options.plus = 0;
	if (t_arg_elem->options.plus)
	{
		if (!(str = apply_option_plus_to_di(t_arg_elem, str, arg)))
			return (NULL);
	}
	else if (t_arg_elem->options.space)
	{
		if (!(str = apply_soustract_to_di(t_arg_elem, arg, str)))
			return (NULL);
		if (!(str = apply_option_space_to_di(t_arg_elem, str, arg)))
			return (NULL);
	}
	else if (t_arg_elem->options.zero)
	{
		if (!(str = apply_option_zero_to_di(t_arg_elem, str, arg)))
			return (NULL);
	}
	if (!(str = apply_last_modif(t_arg_elem, str)))
		return (NULL);
	return (str);
}
