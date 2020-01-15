/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 13:03:28 by asouat            #+#    #+#             */
/*   Updated: 2018/10/03 15:43:23 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *dest;
	char *source;

	dest = (char *)dst;
	source = (char *)src;
	while (n--)
	{
		*dest = *source;
		dest++;
		source++;
	}
	return (dst);
}
