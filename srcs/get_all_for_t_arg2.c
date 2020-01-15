/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_for_t_arg2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:34:32 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 11:55:38 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_arg_for_dioux(t_arg *t_arg_elem, va_list args, t_dioux *dioux)
{
	if (ft_strchr("di", t_arg_elem->type))
	{
		if (get_arg_di(t_arg_elem, args, dioux) == -1)
			return (-1);
	}
	if (ft_strchr("ouxX", t_arg_elem->type))
	{
		if (get_arg_uox(t_arg_elem, args, dioux) == -1)
			return (-1);
	}
	return (0);
}

int			get_arg_for_t_arg(t_arg *t_arg_elem, va_list args, t_dioux *dioux)
{
	if (ft_strchr("diouxX", t_arg_elem->type))
	{
		if (get_arg_for_dioux(t_arg_elem, args, dioux))
			return (-1);
	}
	if (ft_strchr("c", t_arg_elem->type))
	{
		if (get_arg_c(t_arg_elem, args) == -1)
			return (-1);
	}
	if (ft_strchr("s", t_arg_elem->type))
	{
		if (get_arg_s(t_arg_elem, args) == -1)
			return (-1);
	}
	if (ft_strchr("f", t_arg_elem->type))
	{
		if (get_arg_f(t_arg_elem, args) == -1)
			return (-1);
	}
	if (t_arg_elem->type == 'p')
		t_arg_elem->arg = va_arg(args, void *);
	return (0);
}

int			get_precision_for_t_arg(t_arg *t_arg_elem)
{
	char *str;

	if (!(str = ft_strchr(t_arg_elem->settings, '.')))
		return (0);
	else
		str++;
	if (!((*str > '0') && (*str <= '9')))
		t_arg_elem->precision = -1;
	else
	{
		if (!(t_arg_elem->precision = ft_atoi(str)))
			return (-1);
		return (1);
	}
	return (0);
}

void		get_flag_for_t_arg(t_arg *t_arg_elem)
{
	int		i;
	char	*str;
	int		settings_len;

	t_arg_elem->flag = "NULL";
	i = 0;
	settings_len = ft_strlen(t_arg_elem->settings);
	while (i < settings_len && !(ft_isalpha(t_arg_elem->settings[i])))
		i++;
	if ((str = ft_strstr(t_arg_elem->settings + i, "ll")))
		t_arg_elem->flag = "ll";
	else if ((str = ft_strstr(t_arg_elem->settings + i, "hh")))
		t_arg_elem->flag = "hh";
	else if ((str = ft_strchr(t_arg_elem->settings + i, 'h')))
		t_arg_elem->flag = "h";
	else if ((str = ft_strchr(t_arg_elem->settings + i, 'l')))
		t_arg_elem->flag = "l";
	else if ((str = ft_strchr(t_arg_elem->settings + i, 'L')))
		t_arg_elem->flag = "L";
}

int			get_width_min_for_t_arg(t_arg *t_arg_elem)
{
	char	*str;
	char	c;
	int		i;
	int		j;

	i = 1;
	c = t_arg_elem->settings[i];
	while (c && (c != '.'))
	{
		if ((c > 48) && (c <= 57))
		{
			j = i + 1;
			c = t_arg_elem->settings[j];
			while (ft_isdigit(c))
				c = t_arg_elem->settings[++j];
			if (!(str = ft_strsub(t_arg_elem->settings, i, j - i + 1)))
				return (-1);
			if (!(t_arg_elem->width_min = ft_atoi(str)))
				return (-1);
			free(str);
			return (1);
		}
		c = t_arg_elem->settings[++i];
	}
	return (0);
}
