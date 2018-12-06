/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:09:13 by jmoussu           #+#    #+#             */
/*   Updated: 2018/12/06 16:51:34 by jmoussu          ###   ########.fr       */
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

int				get_next_line(const int fd, char **line)
{
	static char *save = NULL;
	int			size;
	int			i;

	i = 0;
	size = 0;
	if (save == NULL)
		save = ft_strdup("");
	*line = ft_strdup("");
	if (ft_error(fd, line) == 1)
		return (-1);
	while (1)
	{
		if ((ft_strchr(save, '\n')) == NULL) // si ya pas de /n dans save
		{
			size = read(fd, *line, BUFF_SIZE);
			if (size == 0)
				break ;
		}
		(*line)[size] = '\0';
		*line = ft_strjoin(save, *line);
		while ((*line)[i] != '\n' || (*line)[i] != '\0')
			i++;
		if ((*line)[i] == '\n') //On a trouver un \n
		{
			(*line)[i] = '\0';
			save = ft_strdup(*line + i + 1);
			return (1);
		}
		if ((*line)[i] == '\0' && size == BUFF_SIZE) // comentairerter
			save = ft_strdup(*line);
		if ((*line)[i] == '\0' && size < BUFF_SIZE) // dfsdfgdfsiou
			return (1);
	}
	return (0);
}