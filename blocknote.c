/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocknote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:02:59 by jmoussu           #+#    #+#             */
/*   Updated: 2018/12/03 15:48:10 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static int	i = 0;
	int			l;
	static	int	g = 0;
	char		buf[BUFF_SIZE + 1];
	static int			size;

	l = i;
	// size = read(fd, buf, BUF_SIZE);
//	ft_putstr("Avant la boucle");
	if (g == 0)
	{
		size = read(fd, buf, BUFF_SIZE);
		g++;
	}
	while (i < size)
	{
		// ft_putstr("Entrée dans la boucle\n");
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			*line = buf + l;
			// ft_putnbr(l);
			i++;
			// ft_putchar('\n');
			// ft_putnbr(i);
			// ft_putstr("\nBackslash N detected\n");
			return (1);
		}
		i++;
	}
	if (g == 1)
	{
		buf[size] = '\0';
		*line = buf + l;
		g++;
		return (1);
	}
//	ft_putstr("Sortie de boucle\n");
	return (0);
}

int		main(int argc, char **argv)
{
	int		retGNL;
	int		fd;
	char	*line;
	line = NULL;
	int i;
	i = 0;
	if (argc <= 1)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open Fail.\n");
		return (1);
	}
	while (i < 20 && (retGNL = get_next_line(fd, &line)))
	{
		ft_putnbr(retGNL);
		ft_putchar('\t');
		ft_putstr(line);
		ft_putchar('\n');
		i++;
	}
	ft_putnbr(get_next_line(fd, &line));
	if (close(fd) == -1)
	{
		ft_putstr("Close Fail.\n");
		return (1);
	}
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:02:59 by jmoussu           #+#    #+#             */
/*   Updated: 2018/11/28 18:48:41 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int			i;
	int			l;
	char		*buf;
	int			rd;
	int 		count;
	int			u;
	int			end;
	static char	str;

	end = 0;
	u = 0;
	count = 0;
	l = i;

	while (end == 0)
	{
		if ((rd = read(fd, buf, BUFF_SIZE)) > 0)
		{
			// ft_putstr("Entrée dans la boucle1\n");
			ft_putnbr(rd);
			ft_putchar('\n');
			while (count < rd)
			{
			// ft_putstr("Entrée dans la boucle2\n");
				if (buf[i] != '\n')
				{
					line[u] = &buf[i];
					i++;
					u++;
					count++;
				}
				else
				{
					buf[i] = '\0';
					line[u] = &buf[i];
					i++;
					count++;
					save = ft_strchr()
					return (1);
				}
			}
		}
		else 
		{
		
		}
		return (0);
	}
}


// /\/\/\/\/\/\/\/\/\ LORAINE /\/\/\/\/\/\/\/\/\/\/\/
// /\/\/\/\/\/\/\/\/\ LORAINE /\/\/\/\/\/\/\/\/\/\/\/
// /\/\/\/\/\/\/\/\/\ LORAINE /\/\/\/\/\/\/\/\/\/\/\/
#include "get_next_line.h"

int		ft_check(int fd, char **str, char **line)
{
	char	buf[BUFF_SIZE];

	if (fd < 0 || line == NULL || read(fd, buf, 0) == -1)
		return (1);
	if (!*str)
	{
		if (!(*str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (1);
	}
	return (0);
}

/*
char	*ft_readallfile(char *str, int fd)
{
	int		size;
	size_t	i;
	size_t	j;
	char	buff[BUFF_SIZE + 1];

	i = 0;
	j = ft_strlen(str);
	while ((size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[size] = '\0';
		while (buff[i] != '\0')
		{
			str[i + j] = buff[i];
			i++;
		}
		j = j + i;
		i = 0;
	}
	str[j] = '\0';
	return (str);
}*/


char	*ft_readallfile(char *str, int fd)
{
	int		size;
	char	buffer[BUFF_SIZE + 1];

	//ft_putstr("salut je read");
	while ((size = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		//ft_putstr("salut je WHILE");
		buffer[size] = '\0';
		if (!(str = ft_strjoin(str, buffer)))
			return (NULL);
	}
	return (str);
}

int		get_next_line(int const fd, char **line)
{
	static char		*str = NULL;
	size_t			i;

	i = 0;
	if (ft_check(fd, &str, line) == 1)
		return (-1);
	if (ft_strcmp(str, "") == 0)
		str = ft_readallfile(str, fd);
	if (str == NULL)
		return (-1);
	while (i < ft_strlen(str))
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			*line = str;
			str = str + i + 1;
			return (1);
		}
		if (str[i + 1] == '\0')
		{
			*line = str;
			str = str + i + 1;
			return (1);
		}
		i++;
	}
	if (!(*line = ft_strdup("")))
		return (-1);
	return (0);
}

/////////////////AUTRE CHECK EROOR/////////////////////
int		ft_error(int fd, char *str, char **line)
{
	char	*buf;
	if (fd < 0 || !line || BUFF_SIZE <= 0 || !(buf = ft_strnew(BUFF_SIZE + 1))
		|| read(fd, buf, 0) == -1 || (str == NULL && !(str = ft_strnew(0))))
		return (1);
	return (0);
}

int     ft_error(int fd, char **str, char **line)
{
	char	buf[BUFF_SIZE];
    //mon fd est > 0 mais a été fermé, check est sensé renvoyer 1 ! comment reperer un fd fermé ?

	if (fd < 0 || !line || read(fd, buf, 0) == -1 )
		return (1);
	return (0);
}

/////////////////AUTRE READ READ/////////////////////

static char	*readfile(char* str, const int fd)
{
	int		size;
	char	*buf;

	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	while((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!str)
			str = ft_strnew(0);
		buf[size] = '\0';
		str = ft_strjoinGNL(str, buf);
		// str = ft_strjoin((str) ? (str) : (""), buf);
	}
	return (str);	
}

char	*readfile(char *str, int fd)
{
	int		size;
	size_t	i;
	size_t	j;
	char	buff[BUFF_SIZE + 1];

	i = 0;
	j = ft_strlen(str);
	while ((size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[size] = '\0';
		while (buff[i] != '\0')
		{
			str[i + j] = buff[i];
			i++;
		}
		j = j + i;
		i = 0;
	}
	str[j] = '\0';
	return (str);
}

/*
static char	*ft_strjoinGNL(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	str = "";
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	j = 0;
	i = 0;
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}
*/
