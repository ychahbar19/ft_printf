/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:55:32 by asouat            #+#    #+#             */
/*   Updated: 2018/10/12 13:53:16 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**str2;

	if (!s || !(str2 = (char **)
				(malloc(sizeof(*str2) * (ft_word_count((char *)s, c) + 1)))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_word_count((char *)s, c))
	{
		k = 0;
		if (!(str2[i] = ft_strnew(ft_word_len((char *)&s[j], c))))
			return (NULL);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str2[i][k++] = s[j++];
		i++;
	}
	str2[i] = 0;
	return (str2);
}
