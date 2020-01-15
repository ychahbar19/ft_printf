/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:44:57 by asouat            #+#    #+#             */
/*   Updated: 2018/10/11 19:31:53 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str1;
	char	*str2;

	j = 0;
	str1 = (char *)haystack;
	str2 = (char *)needle;
	if (!(*str2))
		return (str1);
	while (*str1 && j < len)
	{
		i = 0;
		while (str1[i] == str2[i])
		{
			if (j + i == len)
				return (NULL);
			if (!(str2[++i]))
				return (str1);
		}
		str1++;
		j++;
	}
	return (NULL);
}
