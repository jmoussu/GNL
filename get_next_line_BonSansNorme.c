/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_BonSansNorme.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 21:42:10 by jmoussu           #+#    #+#             */
/*   Updated: 2018/12/08 21:42:13 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_error(int fd, char **line)
{
	char	buf[BUFF_SIZE];

	if (fd < 0 || fd > 4864 || !line || read(fd, buf, 0) == -1)
		return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *save[4864] = {NULL};
	char		buff[BUFF_SIZE + 1];
	char		*startsave;
	int			size;
	int			i;

	i = 0;
	size = 0;
	if (ft_error(fd, line) == 1)
		return (-1);
	if (save[fd] == NULL)
		save[fd] = ft_strdup("");
	while (1)
	{
		if ((ft_strchr(save[fd], '\n')) == NULL)
		{
			size = read(fd, buff, BUFF_SIZE);
			if (size == 0)
				break ;
			if (size < 0)
				return (-1);
		}
		buff[size] = '\0';
		save[fd] = ft_strjoinfree(save[fd], buff, 1);
		while ((save[fd][i] != '\n') && (save[fd][i] != '\0'))
			i++;
		if (save[fd][i] == '\n')
		{
			save[fd][i] = '\0';
			*line = ft_strdup(save[fd]);
			startsave = save[fd];
			save[fd] = ft_strdup(save[fd] + i + 1);
			free(startsave);
			return (1);
		}
	}
	while ((save[fd][i] != '\n') && (save[fd][i] != '\0'))
		i++;
	if (save[fd][i] == '\0' && size < BUFF_SIZE && ft_strlen(save[fd]) > 0)
	{
		*line = ft_strdupfree(save[fd]);
		save[fd] = save[fd] + i;
		return (1);
	}
	return (0);
}
