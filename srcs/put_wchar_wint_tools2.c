/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wchar_wint_tools2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:48:27 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 15:48:49 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wchar_count(wchar_t **ws)
{
	int i;

	i = 0;
	while (ws[i])
		i++;
	return (i);
}

int	wchar_len(wchar_t *ws)
{
	int i;

	i = 0;
	while (ws[i])
		i++;
	return (i);
}

int	wint_len(wint_t *wc)
{
	int i;

	i = 0;
	while (wc[i])
		i++;
	return (i);
}
