/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option_to_di_tools.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 10:36:11 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 10:37:58 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_option_plus_to_di(t_arg *t_arg_elem, char *str, char *arg)
{
	char *ptr;

	if ((t_arg_elem->precision == -1) && !(ft_strcmp("0", str)))
	{
		if (!(ptr = ft_strdup("+")))
			return (NULL);
		free(str);
		str = ptr;
	}
	else if ((t_arg_elem->precision > 0 &&
		str[0] != '-') || (!(t_arg_elem->options.zero)))
	{
		if (!(ptr = ft_strjoin("+", str)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else
	{
		if (!(ptr = ft_strjoin3("+", t_arg_elem->prefix, arg)))
			return (NULL);
		free(str);
		str = ptr;
	}
	return (str);
}

char	*apply_soustract_to_di(t_arg *t_arg_elem, char *arg, char *str)
{
	char *ptr;

	if (t_arg_elem->options.soustract && *t_arg_elem->prefix &&
			arg[0] != '-')
	{
		if (!(ptr = ft_strjoin3(" ", str, t_arg_elem->prefix)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else if (t_arg_elem->options.soustract &&
			*t_arg_elem->prefix && arg[0] == '-')
	{
		if (!(ptr = ft_strjoin(str, t_arg_elem->prefix)))
			return (NULL);
		free(str);
		str = ptr;
	}
	return (str);
}

char	*apply_option_space_to_di(t_arg *t_arg_elem, char *str, char *arg)
{
	char *ptr;

	if (t_arg_elem->options.zero && *t_arg_elem->prefix && arg[0] != '-')
	{
		if (!(ptr = ft_strjoin3(" ", t_arg_elem->prefix, str)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else if ((t_arg_elem->options.zero && *t_arg_elem->prefix && arg[0] == '-'))
	{
		if (!(ptr = ft_strjoin3("-", t_arg_elem->prefix, str + 1)))
			return (NULL);
		free(str);
		str = ptr;
	}
	if ((t_arg_elem->width_min == 1 && arg[0] != '-'))
	{
		if (!(ptr = ft_strjoin(" ", str)))
			return (NULL);
		free(str);
		str = ptr;
	}
	return (str);
}

char	*apply_option_zero_to_di(t_arg *t_arg_elem, char *str, char *arg)
{
	char *ptr;

	if (arg[0] == '-' && *t_arg_elem->prefix)
	{
		if (!(ptr = ft_strjoin3("-", t_arg_elem->prefix, arg + 1)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else if (*t_arg_elem->prefix)
	{
		if (!(ptr = ft_strjoin(t_arg_elem->prefix, arg)))
			return (NULL);
		free(str);
		str = ptr;
	}
	return (str);
}
