/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lluitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:50:07 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 16:50:50 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ucount_digits(unsigned long long n)
{
	size_t	len;

	len = 0;
	while (n >= 1)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_lluitoa(unsigned long long int n)
{
	unsigned int		len;
	char				*str;
	unsigned int		i;
	unsigned long long	nb_save;

	nb_save = n;
	len = ft_ucount_digits(nb_save);
	if (!(str = ft_strnew(len)))
		return (NULL);
	i = len;
	while (nb_save != 0 && i--)
	{
		str[i] = nb_save % 10 + 48;
		nb_save = nb_save / 10;
	}
	return (str);
}
