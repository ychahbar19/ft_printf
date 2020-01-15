/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_for_t_arg1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:34:26 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 11:52:00 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_t_arg_elem_to_last(t_arg *t_args_list, t_arg *new_arg_elem)
{
	t_arg	*list_ptr;

	if (!(t_args_list) || !(new_arg_elem))
		return (0);
	list_ptr = t_args_list;
	while (list_ptr->next)
		list_ptr = list_ptr->next;
	list_ptr->next = new_arg_elem;
	return (1);
}

static int	search_arg_settings(const char *str_format, t_arg *t_arg_elem)
{
	char	*settings;
	int		i;
	int		j;

	i = 0;
	while (str_format[i] && str_format[i] != '%')
		i++;
	j = i + 1;
	while (!(ft_strchr("cspdiouxXf%", str_format[j])))
		j++;
	if (!(str_format[i]) || !(str_format[j]))
		return (0);
	if (!(settings = ft_strsub(str_format, i, j - i + 1)))
		return (-1);
	free(t_arg_elem->settings);
	t_arg_elem->settings = settings;
	return (j);
}

int			get_settings_for_t_arg(const char *str_format, t_arg *t_args_list)
{
	t_arg	*new_arg_elem;
	t_arg	*arg_elem;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arg_elem = t_args_list;
	while (str_format[i])
	{
		if ((j = search_arg_settings(&str_format[i], arg_elem)) == -1)
			return (-1);
		if (j == 0)
			return (1);
		i += j + 1;
		if (!(new_arg_elem = new_t_arg()))
			return (-1);
		if (!(add_t_arg_elem_to_last(t_args_list, new_arg_elem)))
			return (-1);
		arg_elem = arg_elem->next;
	}
	return (0);
}

void		get_type_for_t_arg(t_arg *t_arg_elem)
{
	int i;

	i = ft_strlen(t_arg_elem->settings) - 1;
	t_arg_elem->type = t_arg_elem->settings[i];
}

void		get_options_for_t_arg(t_arg *t_arg_elem)
{
	char	c;
	int		i;

	i = 1;
	c = t_arg_elem->settings[i];
	while (c && !(((c > 48) && (c <= 57)) || (c == '.')))
	{
		if (ft_strchr("-#0+ ", c))
			t_arg_elem->has_options = 1;
		if (c == '+')
			t_arg_elem->options.plus = 1;
		if (c == '-')
			t_arg_elem->options.soustract = 1;
		if (c == '#')
			t_arg_elem->options.diese = 1;
		if (c == '0')
			t_arg_elem->options.zero = 1;
		if (c == ' ')
			t_arg_elem->options.space = 1;
		i++;
		c = t_arg_elem->settings[i];
	}
}
