/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oux_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:13:19 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 14:51:12 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_bits(t_arg *t_arg_elem, unsigned long long int decimal)
{
	int len;

	if (!(ft_strcmp(t_arg_elem->flag, "l")) ||
		!(ft_strcmp(t_arg_elem->flag, "ll")))
		len = 64;
	else
		len = 32;
	return (len);
}

static char	*remove_start_zero_for_o(t_arg *t_arg_elem, char *arg)
{
	int		i;
	char	*tmp;

	if (*arg == '0' && *(arg + 1))
	{
		i = 0;
		while (arg[i] == '0' && (arg[i + 1]))
			i++;
		if (!(tmp = ft_strsub(arg, i, ft_strlen(arg + i))))
			return (NULL);
		free(arg);
		arg = tmp;
	}
	else if (!(*arg))
	{
		if (!(tmp = ft_strdup("0")))
			return (NULL);
		free(arg);
		arg = tmp;
	}
	return (arg);
}

static char	*remove_start_zero_for_x(t_arg *t_arg_elem, char *arg)
{
	int		i;
	char	*tmp;

	if (*arg == '0' && *(arg + 1))
	{
		i = 0;
		while (arg[i] == '0' && (arg[i + 1]))
			i++;
		if (!(tmp = ft_strsub(arg, i, ft_strlen(arg + i))))
			return (NULL);
		free(arg);
		arg = tmp;
	}
	return (arg);
}

static void	*ox_to_str(t_arg *t_arg_elem, char *binary, int len)
{
	void *result;
	char *arg;

	if (t_arg_elem->type == 'o')
	{
		if (!(arg = bin_to_octal(binary, len)))
			return (NULL);
		if (!(ft_strchr("o", t_arg_elem->type) && (*t_arg_elem->flag == 'l') &&
					(binary[63] == 1)))
		{
			if (!(arg = remove_start_zero_for_o(t_arg_elem, arg)))
				return (NULL);
		}
		result = arg;
	}
	if (ft_strchr("xX", t_arg_elem->type))
	{
		if (!(arg = bin_to_hexa(binary, t_arg_elem, len)))
			return (NULL);
		if (!(arg = remove_start_zero_for_x(t_arg_elem, arg)))
			return (NULL);
		result = arg;
	}
	return (result);
}

void		*oux_to_str(t_arg *t_arg_elem, unsigned long long d, t_dioux *dioux)
{
	char *binary;
	void *result;
	char len;

	if (t_arg_elem->type == 'u')
	{
		if (!(result = u_to_str(t_arg_elem, dioux)))
			return (NULL);
	}
	len = nbr_bits(t_arg_elem, d);
	if (!(binary = decimal_to_bin(d, len)))
		return (NULL);
	if (ft_strchr("oxX", t_arg_elem->type))
	{
		if (!(result = ox_to_str(t_arg_elem, binary, len)))
			return (NULL);
		if (ft_strchr("o", t_arg_elem->type) && (*t_arg_elem->flag == 'l') &&
				(LONG_MAX < d && d <= ULONG_MAX))
		{
			if (!(result = ft_strjoin("1", result)))
				return (NULL);
		}
	}
	free(binary);
	return (result);
}
