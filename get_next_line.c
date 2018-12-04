/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:02:59 by jmoussu           #+#    #+#             */
/*   Updated: 2018/12/04 15:56:08 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_error(int fd, char **line)
{
	char	buf[BUFF_SIZE];

	if (fd < 0 || !line || read(fd, buf, 0) == -1)
		return (1);
	return (0);
}

static char		*readfile(char *str, int fd)
{
	int		size;
	char	buffer[BUFF_SIZE + 1];

	while ((size = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[size] = '\0';
		if (!(str = ft_strjoinfree(str, buffer, 1)))
			return (NULL);
	}
	return (str);
}

static int		calc(char **str, char **line)
{
	size_t i;

	i = 0;
	while (str && *str && i < ft_strlen(*str))
	{
		if (*str == NULL)
			return (-1);
		if ((*str)[i] == '\n')
		{
			(*str)[i] = '\0';
			*line = ft_strdup(*str);
			*str = *str + i + 1;
			return (1);
		}
		i++;
	}
	if (str && ft_strlen(*str) > 0)
	{
		*line = ft_strdup(*str);
		*str = *str + i;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	static char *strstart = NULL;
	static int	g = 0;
	int			ret;

	ret = 0;
	if (!(str))
		if (!(str = ft_strdup("")))
			return (-1);
	if (ft_error(fd, line) == 1)
		return (-1);
	// ICI // ICI // ICI // ICI //
	if (ft_strcmp(str, "") == 0)
	{
		if (!(str = readfile(str, fd)))
			return (-1);
	}
	if (strstart == NULL)
		strstart = str;
	ret = calc(&str, line);
	if (ret == 0 && g == 0)
	{
		free (strstart);
		g++;
	}
	return (ret);
}
