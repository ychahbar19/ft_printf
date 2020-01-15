/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:53:37 by asouat            #+#    #+#             */
/*   Updated: 2018/10/06 20:28:57 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!(str = ft_strnew(len)) || !(s))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = (char)s[start];
		i++;
		start++;
	}
	return (str);
}
