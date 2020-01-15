/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_to_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:55:00 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 15:55:58 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	bin_to_decimal(char *binary, unsigned char len)
{
	unsigned int	result;
	unsigned int	pow;
	unsigned short	i;
	unsigned short	j;

	j = len - 1;
	i = 0;
	result = 0;
	while (i < len)
	{
		if (binary[j] == 1)
		{
			pow = power(2, i);
			result += pow;
		}
		j--;
		i++;
	}
	return (result);
}
