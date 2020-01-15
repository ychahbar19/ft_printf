/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wchar_wint_tools1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:47:51 by asouat            #+#    #+#             */
/*   Updated: 2019/04/27 10:19:44 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwint(wint_t *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
}

int		ft_putwchar(t_arg *t_arg_elem, wchar_t **ws_ptr, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len && ws_ptr[i])
	{
		j = 0;
		while (ws_ptr[i][j])
		{
			write(1, &ws_ptr[i][j], 1);
			j++;
		}
		i++;
	}
	return (i);
}

int		wint_size(t_arg *t_arg_elem, wchar_t wc)
{
	int len;

	len = -1;
	if (wc < 128)
		len = 1;
	else if (128 <= wc && wc < 2048)
		len = 2;
	else if (2048 <= wc && wc < 65536)
		len = 3;
	else
		len = 4;
	return (len);
}

int		octet_count(wchar_t **ws)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (ws[i])
	{
		j = 0;
		while (ws[i][j])
		{
			k++;
			j++;
		}
		i++;
	}
	return (k);
}
