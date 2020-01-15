/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:49:09 by asouat            #+#    #+#             */
/*   Updated: 2019/05/16 14:49:14 by asouat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		cpy_to_new_line(char *str[OPEN_MAX], int fd, int i, char **line)
{
	char *tmp;
	char *tmp_line;

	tmp_line = ft_strsub(str[fd], 0, i);
	tmp = ft_strdup(str[fd] + i + 1);
	if (!(tmp_line) || !(tmp))
	{
		free(tmp);
		return (-1);
	}
	free(str[fd]);
	str[fd] = tmp;
	free(*line);
	*line = tmp_line;
	if (!(str[fd][0]))
		ft_strdel(&str[fd]);
	return (0);
}

int		stocker(const int fd, char **line, char **str)
{
	int	i;

	i = 0;
	while (str[fd][i] && (str[fd][i] != '\n'))
		i++;
	if (str[fd][i] == '\n')
	{
		if (cpy_to_new_line(str, fd, i, line) == -1)
			return (-1);
	}
	else if (!(str[fd][i]))
	{
		if (!(*line = ft_strdup(str[fd])))
			return (-1);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		reader(int fd, char buff[BUFF_SIZE + 1], char *str[OPEN_MAX], char *tmp)
{
	int		ret;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(str[fd]))
			str[fd] = ft_strnew(0);
		if (!(tmp = ft_strjoin(str[fd], buff)))
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str[OPEN_MAX];
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	tmp = NULL;
	if ((fd < 0) || (fd >= OPEN_MAX) || !(line) || (BUFF_SIZE <= 0))
		return (-1);
	if (reader(fd, buff, str, tmp) == -1)
		return (-1);
	else if (str[fd] && stocker(fd, line, str))
		return (1);
	return (0);
}
