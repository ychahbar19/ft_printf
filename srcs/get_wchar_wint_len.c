/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wchar_wint_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:03:26 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 14:05:38 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_len_for_wchar(t_arg *t_arg_elem)
{
	int		w_str_len;
	wchar_t	**ws;
	int		len;

	len = 0;
	ws = t_arg_elem->arg;
	if (!(*ws))
	{
		if (*t_arg_elem->prefix)
			ft_putstr(t_arg_elem->prefix);
		free_wchar_t(ws);
		return (ft_strlen(t_arg_elem->prefix));
	}
	if (t_arg_elem->precision > 0)
		w_str_len = wchar_len_for_precision(t_arg_elem, ws);
	else
		w_str_len = wchar_count(ws);
	if (t_arg_elem->width_min > 1)
		len += put_wchar_with_prefix(t_arg_elem, ws, w_str_len);
	else
		len += put_wchar_without_width(t_arg_elem, ws, w_str_len);
	free_wchar_t(ws);
	return (len);
}

int	get_len_for_wint(t_arg *t_arg_elem)
{
	wint_t	*wc;
	int		len;

	len = 0;
	wc = t_arg_elem->arg;
	if (t_arg_elem->options.soustract && t_arg_elem->width_min > 1)
	{
		ft_putwint(wc);
		ft_putstr(t_arg_elem->prefix);
		len += ft_strlen(t_arg_elem->prefix) + wint_len(wc);
	}
	else if (!t_arg_elem->options.soustract && t_arg_elem->width_min > 1)
	{
		ft_putstr(t_arg_elem->prefix);
		ft_putwint(wc);
		len += ft_strlen(t_arg_elem->prefix) + wint_len(wc);
	}
	else
	{
		ft_putwint(wc);
		len += wint_len(wc);
	}
	free(wc);
	return (len);
}
