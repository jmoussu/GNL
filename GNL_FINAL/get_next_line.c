/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:09:13 by jmoussu           #+#    #+#             */
/*   Updated: 2018/12/08 21:20:26 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_error(int fd, char **line, int *size)
{
	char	buf[BUFF_SIZE];

	*size = 0;
	if (fd < 0 || fd > 4864 || !line || read(fd, buf, 0) == -1)
		return (1);
	return (0);
}

int			calcend(char **sfd, int i, int size, char **line)
{
	while (((*sfd)[i] != '\n') && ((*sfd)[i] != '\0'))
		i++;
	if ((*sfd)[i] == '\0' && size < BUFF_SIZE && ft_strlen(*sfd) > 0)
	{
		*line = ft_strdupfree(*sfd);
		*sfd = *sfd + i;
		return (1);
	}
	return (0);
}

char		*lol(char *buff, char **sfd, int *i)
{
	char *startsave;
	char *line;

	*sfd = ft_strjoinfree(*sfd, buff, 1);
	while (((*sfd)[*i] != '\n') && ((*sfd)[*i] != '\0'))
		(*i)++;
	if ((*sfd)[*i] == '\n')
	{
		(*sfd)[*i] = '\0';
		line = ft_strdup(*sfd);
		startsave = *sfd;
		*sfd = ft_strdup(*sfd + *i + 1);
		free(startsave);
		return (line);
	}
	return (NULL);
}

int			get_next_line(const int fd, char **line)
{
	static char *save[4864] = {NULL};
	char		buff[BUFF_SIZE + 1];
	int			size;
	int			i;
	char		*ptr;

	i = 0;
	if (ft_error(fd, line, &size) == 1)
		return (-1);
	(save[fd]) ? (save[fd]) : (save[fd] = ft_strdup(""));
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
		if ((ptr = lol(buff, save + fd, &i)))
			return ((*line = ptr) ? (1) : (0));
	}
	return (calcend(save + fd, i, size, line));
}
