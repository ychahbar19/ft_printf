/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:59:49 by asouat            #+#    #+#             */
/*   Updated: 2018/10/05 15:42:13 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str1;
	char	*str2;

	if (!(*needle))
		return ((char *)haystack);
	str1 = (char *)haystack;
	str2 = (char *)needle;
	while (*str1)
	{
		str1 = (char *)haystack;
		if (*str1 == *str2)
		{
			while ((*str1 == *str2) && *str2)
			{
				str1++;
				str2++;
			}
			if (!(*str2))
				return ((char *)haystack);
			else
				str2 = (char *)needle;
		}
		haystack++;
	}
	return (NULL);
}
