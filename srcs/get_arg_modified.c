/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_modified.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:34:54 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 12:13:29 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_arg_modified_for_diouxcs(t_arg *t_arg_elem, t_dioux *dioux)
{
	char *str;

	if (ft_strchr("di", t_arg_elem->type))
	{
		if (!(str = get_arg_modified_for_di(t_arg_elem, dioux)))
			return (NULL);
	}
	else if (ft_strchr("ouxX", t_arg_elem->type))
	{
		if (!(str = get_arg_modified_for_oux(t_arg_elem)))
			return (NULL);
	}
	else if (ft_strchr("cs", t_arg_elem->type))
	{
		if (!(str = get_arg_modified_for_cs(t_arg_elem)))
			return (NULL);
	}
	return (str);
}

static char	*get_arg_modified_for_pf_pourcent(t_arg *t_arg_elem, t_dioux *dioux)
{
	char *str;

	if (t_arg_elem->type == '%')
	{
		if (!(str = get_arg_modified_for_pourcent(t_arg_elem)))
			return (NULL);
	}
	else if (t_arg_elem->type == 'f')
	{
		if (!(str = get_arg_modified_for_f(t_arg_elem)))
			return (NULL);
	}
	else if (t_arg_elem->type == 'p')
		if (!(str = get_arg_modified_for_p(t_arg_elem)))
			return (NULL);
	return (str);
}

static int	get_ptr_to_arg_modified(t_arg *t_arg_elem, char *str)
{
	char *tmp;

	if ((!(ft_strchr("fo", t_arg_elem->type)) || ((t_arg_elem->type == 'o') &&
	!(t_arg_elem->options.diese))) && (t_arg_elem->precision == -1) &&
	(t_arg_elem->width_min == 1) && (!(ft_strcmp(str, "0"))))
	{
		free(t_arg_elem->arg_modified);
		t_arg_elem->arg_modified = NULL;
	}
	else if ((t_arg_elem->precision == -1) && (t_arg_elem->width_min > 1) &&
		!(ft_strcmp(str + ft_strlen(t_arg_elem->prefix), "0")))
	{
		if (!(tmp = ft_strdup(t_arg_elem->prefix)))
			return (-1);
		free(t_arg_elem->arg_modified);
		t_arg_elem->arg_modified = tmp;
	}
	else
	{
		if (!(tmp = ft_strdup(str)))
			return (-1);
		free(t_arg_elem->arg_modified);
		t_arg_elem->arg_modified = tmp;
	}
	return (0);
}

int			get_arg_modified(t_arg *t_arg_elem, t_dioux *dioux)
{
	char	*str;
	char	*tmp;

	if (ft_strchr("diouxXcs", t_arg_elem->type))
	{
		if (!(str = get_arg_modified_for_diouxcs(t_arg_elem, dioux)))
			return (-1);
	}
	else if (ft_strchr("fp%", t_arg_elem->type))
	{
		if (!(str = get_arg_modified_for_pf_pourcent(t_arg_elem, dioux)))
			return (-1);
	}
	if (ft_strchr(t_arg_elem->settings, '#'))
		t_arg_elem->options.diese = 1;
	if (get_ptr_to_arg_modified(t_arg_elem, str) == -1)
		return (-1);
	free(str);
	return (1);
}
