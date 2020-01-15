/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:52:54 by asouat            #+#    #+#             */
/*   Updated: 2019/05/08 17:45:17 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_report(char *str, int *report, int i)
{
	while (str[i] && *report)
	{
		if (str[i] == '9')
		{
			*report = 1;
			str[i] = '0';
		}
		else if (str[i] != '-')
		{
			*report = 0;
			str[i] += 1;
		}
		i--;
	}
	if (i < 0)
		*report = 1;
}

int			ft_round_num(char *str, int len, int report)
{
	int i;

	if (str[len - 1] == '9')
	{
		i = len - 1;
		report = 1;
		get_report(str, &report, i);
	}
	else
	{
		str[len - 1] += 1;
		report = 0;
	}
	return (report);
}
