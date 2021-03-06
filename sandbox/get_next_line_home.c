/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:13:44 by marvin            #+#    #+#             */
/*   Updated: 2018/12/04 21:13:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_error(int fd, char **line)
{
	char	buf[BUFF_SIZE];

	if (fd < 0 || !line || read(fd, buf, 0) == -1 || BUFF_SIZE <= 0)
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
			break;
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
	// {
	// 	if (!(str = readfile(str, fd)))
	// 		return (-1);
	// }
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
int				get_next_line_home(const int fd, char **line)
{
	static char *save = NULL;
	char		*str;
	static int	size;
	static int	ftr;
	int			i;
	char		buffer[BUFF_SIZE + 1];

	size = 0;
	i = 0;
	if(save == NULL)
		save = strdup("");
	str = strdup("");

	if (ftr == 1)
	{
		size = read(fd, buffer, BUFF_SIZE);
		buffer[size] = '\0';
		str = ft_strdup(buffer);
	}
	else
	{
		str = ft_strdup(save);
	}
	if (BUFF_SIZE == SIZE)
	{
			while (i < ft_strlen(str))
		{
			// if (str == NULL or "" ?)
			// 	return (-1);
			if ((str)[i] == '\n')
			{
				(str)[i] = '\0';
				*line = ft_strjoint(save, str);
				str = str + i + 1
				save = ft_strdup(str);
				ftr = 0;
				return (1);
			}
			i++;
		}
		if (ft_strlen(str) > 0)
		{
			save = ft_strjoint(save, str);
			ftr = 1;
			// str = str + i + 1; OFFSET DU READ
		}
	}
	// géré les donné de la fin plus jamais read
	return (0);

}



// 2222222222222222222222222222222222222222//

int				get_next_line_home(const int fd, char **line)
{
	static char *save = NULL;
	char		*str;
	static int	size = 0;
	static int	ftr = 1;
	int			i;
	char		buffer[BUFF_SIZE + 1];

	size = 0;
	i = 0;
	if(save == NULL)
		save = strdup("");
	str = strdup("");

	while (ftr == 1)
	{
		size = read(fd, buffer, BUFF_SIZE);
		buffer[size] = '\0';
	if (BUFF_SIZE > SIZE)
	{
		ret = calc(&str, line); // et LE save ?
		ftr = 0;
	}
	else
	{
		while (i < ft_strlen(str))
		{
			// if (str == NULL or "" ?)
			// 	return (-1);
			if ((str)[i] == '\n')
			{
				(str)[i] = '\0';
				*line = ft_strjoint(save, str);
				str = str + i + 1
				save = ft_strdup(str);
				return (1);
			}
			i++;
		}
		if (ft_strlen(str) > 0)
		{
			save = ft_strjoint(save, str);
			// str = str + i + 1; OFFSET DU READ
		}
	}
	}
	// géré les donné de la fin plus jamais read
	return (ret);
}
