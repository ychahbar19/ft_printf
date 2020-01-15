/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option_to_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:49:14 by asouat            #+#    #+#             */
/*   Updated: 2019/04/27 15:49:18 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_option_to_u(t_arg *t_arg_elem, char *str, char *arg)
{
	char *ptr;

	if (t_arg_elem->options.soustract && *t_arg_elem->prefix)
	{
		if (!(ptr = ft_strjoin(str, t_arg_elem->prefix)))
			return (NULL);
		free(str);
		str = ptr;
	}
	else if (*t_arg_elem->prefix)
	{
		if (!(ptr = ft_strjoin(t_arg_elem->prefix, str)))
			return (NULL);
		free(str);
		str = ptr;
	}
	return (str);
}
