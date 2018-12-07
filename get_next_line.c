/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:09:13 by jmoussu           #+#    #+#             */
/*   Updated: 2018/12/07 18:51:41 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdupfree(char *src)
{
	int		i;
	char	*dest;

	if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	free(src);
	return (dest);
}


int				ft_error(int fd, char **line)
{
	char	buf[BUFF_SIZE];

	if (fd < 0 || fd > 4864 || !line || read(fd, buf, 0) == -1)
		return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *save[4864] = {NULL}; // ulimit -m 4864
	char		buff[BUFF_SIZE + 1];
	char		*startsave;
	// char		*str;
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
		if ((ft_strchr(save[fd], '\n')) == NULL) // si ya pas de /n dans save
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
		if (save[fd][i] == '\n') //On a trouver un \n
		{
			save[fd][i] = '\0';
			*line = ft_strdup(save[fd]);
			startsave = save[fd];
			save[fd] = ft_strdup(save[fd] + i + 1);
			free(startsave);

			return (1);
		}
		// if (save[fd][i] == '\0' && size == BUFF_SIZE) // comentairerter
		// 	continue ;
	}
		while ((save[fd][i] != '\n') && (save[fd][i] != '\0'))
			i++;
		if (save[fd][i] == '\0' && size < BUFF_SIZE && ft_strlen(save[fd]) > 0) // dfsdfgdfsiou
		{
			// *line = ft_strdup(save[fd]);
			*line = ft_strdup(save[fd]);
			save[fd] = ft_strdup(save[fd] + i);
			return (1);
		}
	return (0);
}