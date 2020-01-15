/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option_to_f_tools.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:16:31 by asouat            #+#    #+#             */
/*   Updated: 2019/05/08 15:18:48 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_zero_space_to_f(t_arg *t_arg_elem, char *str, char *arg)
{
	char *ptr;

	if (t_arg_elem->options.zero && arg[0] != '-')
	{
		if (!(ptr = ft_strjoin3(" ", t_arg_elem->prefix, arg)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else if (t_arg_elem->options.zero && arg[0] == '-')
	{
		if (!(ptr = ft_strjoin3("-", t_arg_elem->prefix, arg + 1)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else if (arg[0] != '-')
	{
		if (!(ptr = ft_strjoin(" ", arg)))
			return (NULL);
		free(str);
		str = ptr;
	}
	return (str);
}

char	*apply_option_plus_to_f(t_arg *t_arg_elem, char *str, char *arg)
{
	char *ptr;

	if ((arg[0] != '-') &&
			((t_arg_elem->precision > 0) || !(t_arg_elem->options.zero)))
	{
		if (!(ptr = ft_strjoin("+", arg)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else if (arg[0] != '-')
	{
		if (!(ptr = ft_strjoin3("+", t_arg_elem->prefix, arg)))
			return (NULL);
		free(str);
		str = ptr;
	}
	return (str);
}

char	*apply_option_space_to_f(t_arg *t_arg_elem, char *str, char *arg)
{
	char	*ptr;

	if (t_arg_elem->options.soustract && arg[0] != '-')
	{
		if (!(ptr = ft_strjoin3(" ", str, t_arg_elem->prefix)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else if (t_arg_elem->options.soustract && arg[0] == '-')
	{
		if (!(ptr = ft_strjoin(str, t_arg_elem->prefix)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else
	{
		if (!(str = apply_zero_space_to_f(t_arg_elem, str, arg)))
			return (NULL);
	}
	return (str);
}

char	*apply_option_zero_to_f(t_arg *t_arg_elem, char *str, char *arg)
{
	char *ptr;

	if (arg[0] == '-')
	{
		if (!(ptr = ft_strjoin3("-", t_arg_elem->prefix, arg + 1)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else
	{
		if (!(ptr = ft_strjoin(t_arg_elem->prefix, arg)))
			return (NULL);
		free(str);
		str = ptr;
	}
	return (str);
}

char	*apply_option_diese_to_f(t_arg *t_arg_elem, char *str_entier)
{
	char *str;

	if (!t_arg_elem->options.diese)
	{
		if (!(str = ft_strdup(str_entier)))
			return (NULL);
	}
	else
	{
		if (!(str = ft_strjoin(str_entier, ".")))
			return (NULL);
	}
	return (str);
}
