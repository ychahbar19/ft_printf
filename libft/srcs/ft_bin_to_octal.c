/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_to_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:16:20 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 16:41:40 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	octal_len(unsigned char len)
{
	int	len_octal;

	if (len == 32)
		len_octal = 11;
	else
		len_octal = 21;
	return (len_octal);
}

char		*bin_to_octal(char *binary, unsigned char len)
{
	unsigned long long int	result;
	unsigned int			i;
	unsigned int			j;
	unsigned int			k;
	char					*octal;

	if (!(octal = ft_strnew(octal_len(len))))
		return (NULL);
	i = -1;
	j = 0;
	k = octal_len(len) - 1;
	result = 0;
	while (++i < len)
	{
		if (binary[i] == 1)
			result += power(2, j);
		if (++j == 3 || (j == 2 && k == 0 && len == 32))
		{
			octal[k] = result + 48;
			result = 0;
			j = 0;
			k--;
		}
	}
	return (octal);
}
