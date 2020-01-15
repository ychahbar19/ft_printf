/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:35:13 by asouat            #+#    #+#             */
/*   Updated: 2019/04/27 10:18:53 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_wchar_len_for_prefix(wchar_t *ws)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (ws[i])
	{
		if (ws[i] < 128)
			len++;
		else if (128 <= ws[i] && ws[i] < 2048)
			len += 2;
		else if (2048 <= ws[i] && ws[i] < 65536)
			len += 3;
		else
			len += 4;
		i++;
	}
	return (len);
}

static int	get_prefix_for_wchar(t_arg *t_arg_elem, wchar_t *ws, char *arg)
{
	char	*ptr;
	int		pre_len;
	int		wchar_len;
	int		len;

	if (get_prefix(t_arg_elem, arg) == -1)
		return (-1);
	pre_len = ft_strlen(t_arg_elem->prefix);
	wchar_len = get_wchar_len_for_prefix(ws);
	if (t_arg_elem->width_min > 1 && t_arg_elem->precision > 0)
		len = pre_len - t_arg_elem->precision;
	else
		len = pre_len - wchar_len;
	if (len > 0 && *ws)
	{
		if (!(ptr = ft_strsub(t_arg_elem->prefix, 0, len)))
			return (-1);
		free(t_arg_elem->prefix);
		t_arg_elem->prefix = ptr;
	}
	return (0);
}

wchar_t		**get_ws(t_arg *t_arg_elem, wchar_t *ws)
{
	unsigned char	w_int_len;
	unsigned char	ws_len;
	wchar_t			**ws_ptr;
	int				i;

	ws_len = wchar_len(ws);
	if (!(ws_ptr = (wchar_t **)malloc(sizeof(wchar_t *) * (ws_len + 1))))
		return (NULL);
	ws_ptr[ws_len] = 0;
	i = 0;
	while (i < ws_len)
	{
		w_int_len = wint_size(t_arg_elem, ws[i]);
		if (!(ws_ptr[i] = (wchar_t *)malloc(sizeof(wchar_t) * (w_int_len + 1))))
			return (NULL);
		ws_ptr[i][w_int_len] = 0;
		if (get_utf8(ws[i], (wint_t *)ws_ptr[i], w_int_len) == -1)
			return (NULL);
		i++;
	}
	return (ws_ptr);
}

int			get_wchar(t_arg *t_arg_elem, va_list args)
{
	wchar_t	**ws_ptr;
	wchar_t	*ws;
	char	*tmp;
	char	*arg;

	ws = va_arg(args, wchar_t *);
	if (ws == NULL)
	{
		if (!(tmp = ft_strdup("(null)")))
			return (-1);
		free(t_arg_elem->arg_modified);
		t_arg_elem->arg_modified = tmp;
		t_arg_elem->flag = "";
		return (0);
	}
	arg = "";
	if ((get_prefix_for_wchar(t_arg_elem, ws, arg)) == -1)
		return (-1);
	if (!(ws_ptr = get_ws(t_arg_elem, ws)))
		return (-1);
	t_arg_elem->arg = ws_ptr;
	return (0);
}

int			get_arg_s(t_arg *t_arg_elem, va_list args)
{
	char *str;

	if (!(ft_strcmp(t_arg_elem->flag, "l")))
	{
		if (get_wchar(t_arg_elem, args) == -1)
			return (-1);
	}
	else
	{
		str = va_arg(args, char *);
		t_arg_elem->arg = str;
	}
	return (0);
}
