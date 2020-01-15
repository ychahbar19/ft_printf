/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:34:40 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 11:58:02 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	wint_and_prefix_len(t_arg *t_arg_elem, wint_t wc)
{
	int		size;
	int		len;
	char	*ptr;

	size = -1;
	if (wc < 128)
		size = 1;
	else if (128 <= wc && wc < 2048)
		size = 2;
	else if (2048 <= wc && wc < 65536)
		size = 3;
	else
		size = 4;
	len = ft_strlen(t_arg_elem->prefix) - size + 1;
	if (len > 0)
	{
		if (!(ptr = ft_strsub(t_arg_elem->prefix, 0, len)))
			return (-1);
		free(t_arg_elem->prefix);
		t_arg_elem->prefix = ptr;
	}
	return (size);
}

int			get_wint(t_arg *t_arg_elem, va_list args)
{
	char	len;
	wint_t	wc1;
	wint_t	*wc2;
	char	*arg;

	wc1 = va_arg(args, wint_t);
	if (get_prefix(t_arg_elem, arg) == -1)
		return (-1);
	if ((len = wint_and_prefix_len(t_arg_elem, wc1)) == -1)
		return (-1);
	if (!(wc2 = (wint_t *)malloc(sizeof(wint_t) * len + 1)))
		return (-1);
	wc2[len] = '\0';
	if (get_utf8(wc1, wc2, len) == -1)
	{
		free(wc2);
		return (-1);
	}
	t_arg_elem->arg = wc2;
	return (0);
}

int			get_arg_c(t_arg *t_arg_elem, va_list args)
{
	char *c;

	if (!(ft_strcmp(t_arg_elem->flag, "l")))
	{
		if (get_wint(t_arg_elem, args) == -1)
			return (-1);
	}
	else
	{
		if (!(c = ft_strnew(1)))
			return (-1);
		*c = (char)va_arg(args, int);
		t_arg_elem->arg = c;
	}
	return (0);
}
