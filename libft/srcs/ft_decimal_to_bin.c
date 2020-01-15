/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_bin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:41:57 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 16:42:38 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*decimal_to_bin(unsigned long long decimal, char len)
{
	char				*binary;
	unsigned long long	result;
	int					i;

	if (!(binary = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_bzero(binary, len);
	i = 0;
	result = decimal;
	while (result && i < len)
	{
		binary[i] = result % 2;
		result = result / 2;
		i++;
	}
	return (binary);
}
