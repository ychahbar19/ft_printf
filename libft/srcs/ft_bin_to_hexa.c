/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_to_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:56:08 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 16:16:07 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	get_hexa(t_arg *arg, unsigned long long result)
{
	char hexa;

	if (result < 10)
		hexa = result + 48;
	else
	{
		if (arg->type == 'X')
			hexa = result + 55;
		else
			hexa = result + 87;
	}
	return (hexa);
}

char		*bin_to_hexa(char *binary, t_arg *arg, unsigned char len)
{
	unsigned long long	result;
	unsigned int		i;
	unsigned int		j;
	unsigned int		k;
	char				*hexa;

	if (!(hexa = ft_strnew(len / 4)))
		return (0);
	i = -1;
	j = 0;
	k = (len / 4) - 1;
	result = 0;
	while (++i < len)
	{
		if (binary[i] == 1)
			result += power(2, j);
		if (++j == 4)
		{
			hexa[k] = get_hexa(arg, result);
			result = 0;
			j = 0;
			k--;
		}
	}
	return (hexa);
}
