/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_modified_for_p.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:41:44 by asouat            #+#    #+#             */
/*   Updated: 2019/05/08 15:47:36 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_ptr_null_precision(t_arg *t_arg_elem)
{
	char *hexa;

	if (t_arg_elem->precision == -1)
	{
		if (!(hexa = ft_strdup("0x")))
			return (NULL);
	}
	else if (t_arg_elem->precision)
	{
		if (!(hexa = apply_precision(t_arg_elem, hexa)))
			return (NULL);
		if (!(hexa = ft_strjoin("0x", hexa)))
			return (NULL);
	}
	else
	{
		if (!(hexa = ft_strdup("0x0")))
			return (NULL);
	}
	return (hexa);
}

static char		*get_ptr_null(t_arg *t_arg_elem)
{
	char *hexa;

	if (get_prefix(t_arg_elem, "0") == -1)
		return (NULL);
	if (!(hexa = get_ptr_null_precision(t_arg_elem)))
		return (NULL);
	if ((t_arg_elem->width_min > 1) && *t_arg_elem->prefix)
	{
		if (t_arg_elem->options.soustract)
		{
			if (!(hexa = ft_strjoin(hexa, t_arg_elem->prefix)))
				return (NULL);
		}
		else
		{
			if (!(hexa = ft_strjoin(t_arg_elem->prefix, hexa)))
				return (NULL);
		}
	}
	return (hexa);
}

static char		*get_ptr_precision(t_arg *t_arg_elem, char *hexa)
{
	char	*tmp;
	int		i;

	if ((t_arg_elem->precision) || (t_arg_elem->width_min > 1) ||
			(!(t_arg_elem->precision) && (t_arg_elem->width_min == 1)))
	{
		i = 0;
		while (hexa[i] == '0')
			i++;
		if (!(tmp = ft_strsub(hexa, i, ft_strlen(hexa) - i)))
			return (NULL);
		free(hexa);
		hexa = tmp;
	}
	if (get_prefix(t_arg_elem, hexa) == -1)
		return (NULL);
	if (t_arg_elem->precision > 0 && t_arg_elem->precision > ft_strlen(hexa))
	{
		if (!(tmp = apply_precision(t_arg_elem, hexa)))
			return (NULL);
		free(hexa);
		hexa = tmp;
	}
	return (hexa);
}

static char		*get_ptr(t_arg *t_arg_elem, char *hexa)
{
	char *tmp;

	if (!(hexa = get_ptr_precision(t_arg_elem, hexa)))
		return (NULL);
	if (get_prefix(t_arg_elem, hexa) == -1)
		return (NULL);
	if (t_arg_elem->options.soustract || t_arg_elem->width_min == 1)
	{
		if (!(tmp = ft_strjoin3("0x", hexa, t_arg_elem->prefix)))
			return (NULL);
		free(hexa);
		hexa = tmp;
	}
	else
	{
		if (!(tmp = ft_strjoin3(t_arg_elem->prefix, "0x", hexa)))
			return (NULL);
		free(hexa);
		hexa = tmp;
	}
	return (hexa);
}

char			*get_arg_modified_for_p(t_arg *t_arg_elem)
{
	unsigned long long	ptr;
	char				*hexa;
	char				*binary;
	char				*tmp;

	ptr = (unsigned long long)t_arg_elem->arg;
	if (ptr == 0)
	{
		if (!(hexa = get_ptr_null(t_arg_elem)))
			return (NULL);
	}
	else
	{
		if (!(binary = decimal_to_bin(ptr, 64)))
			return (NULL);
		if (!(hexa = bin_to_hexa(binary, t_arg_elem, 64)))
			return (NULL);
		if (!(hexa = get_ptr(t_arg_elem, hexa)))
			return (NULL);
		free(binary);
	}
	return (hexa);
}
