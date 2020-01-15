/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:10:34 by asouat            #+#    #+#             */
/*   Updated: 2018/10/09 17:42:34 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	size_t	i;
	long	nb_save;

	nb_save = n;
	len = ft_count_digits(nb_save);
	if (!(str = ft_strnew(len)))
		return (NULL);
	i = len;
	if (nb_save < 0)
	{
		nb_save = -nb_save;
		str[0] = '-';
	}
	while (nb_save >= 0 && i--)
	{
		if (i || str[0] != '-')
			str[i] = nb_save % 10 + 48;
		nb_save = nb_save / 10;
	}
	return (str);
}
