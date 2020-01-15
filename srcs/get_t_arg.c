/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:01:06 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 14:03:13 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	*new_t_arg(void)
{
	t_arg *t_arg_elem;

	if (!(t_arg_elem = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	t_arg_elem->flag = 0;
	t_arg_elem->options.plus = 0;
	t_arg_elem->options.soustract = 0;
	t_arg_elem->options.diese = 0;
	t_arg_elem->options.zero = 0;
	t_arg_elem->options.space = 0;
	t_arg_elem->has_options = 0;
	t_arg_elem->width_min = 1;
	t_arg_elem->precision = 0;
	t_arg_elem->next = NULL;
	if (!(t_arg_elem->prefix = ft_strnew(0)))
		return (NULL);
	if (!(t_arg_elem->arg_modified = ft_strnew(0)))
		return (NULL);
	if (!(t_arg_elem->settings = ft_strnew(0)))
		return (NULL);
	return (t_arg_elem);
}

int		get_t_args(const char *str_format, t_arg *args_list)
{
	t_arg *t_arg_elem;

	if (str_format == NULL)
		return (-1);
	if (get_settings_for_t_arg(str_format, args_list) == -1)
		return (-1);
	t_arg_elem = args_list;
	while (t_arg_elem->next)
	{
		get_type_for_t_arg(t_arg_elem);
		get_options_for_t_arg(t_arg_elem);
		if (get_width_min_for_t_arg(t_arg_elem) == -1)
			return (-1);
		if (get_precision_for_t_arg(t_arg_elem) == -1)
			return (-1);
		get_flag_for_t_arg(t_arg_elem);
		t_arg_elem = t_arg_elem->next;
	}
	return (0);
}
