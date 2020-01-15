/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:57:34 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 16:57:56 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	unsigned int	len;
	char			*str;
	unsigned int	i;
	long			nb_save;

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
