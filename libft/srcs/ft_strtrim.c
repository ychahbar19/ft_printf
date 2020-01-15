/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:09:23 by asouat            #+#    #+#             */
/*   Updated: 2018/10/11 19:24:40 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*str;

	if (!(s))
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] && ((s[start] == '\n') ||
				(s[start] == '\t') || (s[start] == ' ')))
		start++;
	while (end > 0 && ((s[end] == '\n') ||
				(s[end] == '\t') || (s[end] == ' ')))
		end--;
	if ((end == 0) && (start == ft_strlen(s)))
		len = 0;
	else
		len = end - start + 1;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str = ft_strsub(s, (unsigned int)start, len);
	return (str);
}
