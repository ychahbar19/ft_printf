/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 12:32:28 by asouat            #+#    #+#             */
/*   Updated: 2018/10/03 15:38:15 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	x;

	str = (unsigned char *)b;
	x = (unsigned char)c;
	while (len--)
	{
		*str = x;
		str++;
	}
	return (b);
}
