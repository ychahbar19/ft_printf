/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wchar_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:46:22 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 15:47:14 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wchar_len_for_precision(t_arg *t_arg_elem, wchar_t **ws)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (k < t_arg_elem->precision && ws[i])
	{
		j = 0;
		while (k < t_arg_elem->precision && ws[i][j])
		{
			k++;
			j++;
		}
		i++;
	}
	if (!ws[i][j])
		k = i;
	else
		k = i - 1;
	return (k);
}

int	octet_count_with_precision(t_arg *t_arg_elem, wchar_t **ws)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (k < t_arg_elem->precision && ws[i])
	{
		j = 0;
		while (k < t_arg_elem->precision && ws[i][j])
		{
			k++;
			j++;
		}
		i++;
	}
	if (ws[i][j])
		k -= j;
	return (k);
}

int	put_wchar_with_soustract(t_arg *t_arg_elem, wchar_t **ws, int w_str_len)
{
	int len;
	int octet_counter;

	octet_counter = octet_count(ws);
	len = 0;
	ft_putwchar(t_arg_elem, ws, w_str_len);
	if (octet_counter < t_arg_elem->width_min || *t_arg_elem->prefix)
	{
		ft_putstr(t_arg_elem->prefix);
		len += ft_strlen(t_arg_elem->prefix);
	}
	if (t_arg_elem->precision == 0)
		len += octet_counter;
	else
		len += t_arg_elem->precision;
	return (len);
}

int	put_wchar_with_prefix(t_arg *t_arg_elem, wchar_t **ws, int w_str_len)
{
	int len;
	int octet_counter;

	octet_counter = octet_count(ws);
	len = 0;
	if (t_arg_elem->options.soustract)
	{
		len += put_wchar_with_soustract(t_arg_elem, ws, w_str_len);
	}
	else
	{
		if (octet_counter < t_arg_elem->width_min || *t_arg_elem->prefix)
		{
			ft_putstr(t_arg_elem->prefix);
			len += ft_strlen(t_arg_elem->prefix);
		}
		ft_putwchar(t_arg_elem, ws, w_str_len);
		if (t_arg_elem->precision == 0)
			len += octet_counter;
		else
			len += t_arg_elem->precision;
	}
	return (len);
}

int	put_wchar_without_width(t_arg *t_arg_elem, wchar_t **ws, int w_str_len)
{
	int len;

	len = 0;
	if (t_arg_elem->precision == 0)
	{
		ft_putwchar(t_arg_elem, ws, w_str_len);
		len += octet_count(ws);
	}
	else if ((t_arg_elem->precision > 0))
	{
		ft_putwchar(t_arg_elem, ws, w_str_len);
		len += octet_count_with_precision(t_arg_elem, ws);
	}
	return (len);
}
