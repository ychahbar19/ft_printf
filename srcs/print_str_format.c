/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:35:42 by asouat            #+#    #+#             */
/*   Updated: 2019/05/08 16:24:56 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			putchar_null(t_arg *t_arg_elem, char *c)
{
	int len;

	len = 0;
	if (t_arg_elem->options.soustract && t_arg_elem->width_min > 1)
	{
		ft_putchar(*c);
		ft_putstr(t_arg_elem->prefix);
		len += ft_strlen(t_arg_elem->prefix) + 1;
	}
	else if (!t_arg_elem->options.soustract && t_arg_elem->width_min > 1)
	{
		ft_putstr(t_arg_elem->prefix);
		ft_putchar(*c);
		len += ft_strlen(t_arg_elem->prefix) + 1;
	}
	else
	{
		ft_putchar(*c);
		len++;
	}
	free(c);
	return (len);
}

int					put_wchar_wint(t_arg *t_arg_elem)
{
	wchar_t	**ws;
	int		len;

	len = 0;
	if (t_arg_elem->type == 'c' && !(ft_strcmp(t_arg_elem->flag, "l")))
	{
		len += get_len_for_wint(t_arg_elem);
	}
	else if (t_arg_elem->type == 's' && !(ft_strcmp(t_arg_elem->flag, "l")))
	{
		len += get_len_for_wchar(t_arg_elem);
	}
	return (len);
}

static int			put_arg(t_arg *t_arg_elem, const char *str_format, char *c)
{
	int len;

	len = 0;
	if (t_arg_elem->type == 'c' && !(*c))
	{
		len += putchar_null(t_arg_elem, c);
	}
	else if (ft_strchr("cs", t_arg_elem->type) &&
					!(ft_strcmp(t_arg_elem->flag, "l")))
	{
		len += put_wchar_wint(t_arg_elem);
	}
	else if (t_arg_elem->arg_modified)
	{
		if (ft_strchr("u", t_arg_elem->type) && (*t_arg_elem->flag == 'l') &&
				!(*t_arg_elem->arg_modified))
		{
			ft_putchar('0');
			len++;
		}
		ft_putstr(t_arg_elem->arg_modified);
		len += ft_strlen(t_arg_elem->arg_modified);
	}
	return (len);
}

static const char	*print_simple_str(const char *str_format, int *len)
{
	while (*str_format && *str_format != '%')
	{
		ft_putchar(*str_format);
		str_format++;
		*len += 1;
	}
	return (str_format);
}

int					print_str_format(t_arg *t_arg_elem, const char *s, int len)
{
	char	*c;
	int		*len_ptr;

	if (!(len_ptr = (int *)malloc(sizeof(int))))
		return (-1);
	*len_ptr = 0;
	while (*s)
	{
		c = t_arg_elem->arg;
		s = print_simple_str(s, len_ptr);
		if (*s == '%')
		{
			if (*t_arg_elem->settings)
			{
				*len_ptr += put_arg(t_arg_elem, s, c);
				s = ft_strrstr(s, t_arg_elem->settings);
				t_arg_elem = t_arg_elem->next;
			}
			else
				s++;
		}
	}
	len = *len_ptr;
	free(len_ptr);
	return (len);
}
