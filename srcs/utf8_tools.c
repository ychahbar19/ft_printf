/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:35:48 by asouat            #+#    #+#             */
/*   Updated: 2019/04/26 18:38:24 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	start_index(unsigned char len)
{
	unsigned short start;

	if (len == 1)
		start = 6;
	else if (len == 2)
		start = 10;
	else if (len == 3)
		start = 15;
	else
		start = 20;
	return (start);
}

static char	*mask_for_big_size(void)
{
	char *tmp;
	char *mask_utf8;

	if (!(tmp = ft_strjoin("11110xxx", "10xxxxxx")))
		return (NULL);
	if (!(mask_utf8 = ft_strjoin3(tmp, "10xxxxxx", "10xxxxxx")))
		return (NULL);
	free(tmp);
	return (mask_utf8);
}

int			get_mask_utf8(char **mask_utf8, unsigned char len)
{
	char *tmp;

	if (len == 1)
	{
		if (!(*mask_utf8 = ft_strdup("0xxxxxxx")))
			return (-1);
	}
	else if (len == 2)
	{
		if (!(*mask_utf8 = ft_strjoin("110xxxxx", "10xxxxxx")))
			return (-1);
	}
	else if (len == 3)
	{
		if (!(*mask_utf8 = ft_strjoin3("1110xxxx", "10xxxxxx", "10xxxxxx")))
			return (-1);
	}
	else
	{
		if (!(*mask_utf8 = mask_for_big_size()))
			return (-1);
	}
	return (0);
}

static char	*apply_mask_utf8(char *mask_utf8, char *binary, unsigned char len)
{
	int	i;
	int	start;

	i = -1;
	start = start_index(len);
	while (mask_utf8[++i])
	{
		if (mask_utf8[i] == 'x')
		{
			mask_utf8[i] = binary[start];
			start--;
		}
		else
			mask_utf8[i] -= 48;
	}
	return (mask_utf8);
}

int			get_utf8(wint_t wc1, wint_t *wc2, unsigned char len)
{
	char	*mask_utf8;
	char	*binary;
	int		i;
	int		j;

	if (!(binary = decimal_to_bin(wc1, 32)))
		return (-1);
	if (get_mask_utf8(&mask_utf8, len) == -1)
		return (-1);
	mask_utf8 = apply_mask_utf8(mask_utf8, binary, len);
	i = -1;
	j = 0;
	while (++i < len)
	{
		if (!(wc2[i] = bin_to_decimal(&mask_utf8[j], 8)))
		{
			free(binary);
			free(mask_utf8);
		}
		j += 8;
	}
	free(binary);
	free(mask_utf8);
	return (0);
}
