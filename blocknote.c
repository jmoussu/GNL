/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocknote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:02:59 by jmoussu           #+#    #+#             */
/*   Updated: 2018/12/01 15:02:49 by jmoussu          ###   ########.fr       */
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
int     ft_check(int fd, char **str, char **line)
{
    char    buf[BUFF_SIZE];
    //mon fd est > 0 mais a été fermé, check est sensé renvoyer 1 ! comment reperer un fd fermé ?
    if (fd < 0 || line == NULL || read(fd, buf, 0) == -1)
        return (1);
    if (!*str)
    {
        if (!(*str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
            return (1);
    }
    return (0);
}
char    *ft_readallfile(char *str, int fd)
{
    int     size;
    char    buffer[BUFF_SIZE + 1];
    //char  *str_tmp;
    //str_tmp = "";
    while ((size = read(fd, buffer, BUFF_SIZE)) > 0)
    {
        buffer[size] = '\0'; //pour eviter des problemes dans la memoire, buffer est utilisé en tant que string dans strjoin et doit avoir son '\0'
        str = ft_strjoin(str, buffer); //le buffer va etre ecrasé a chaque lecture de read donc on ajoute chaque nouveauté dans str avec join, join ecrase les '\0'
        //free(str);
        //str = str_tmp;
    }
    return (str);
}
int     get_next_line(int const fd, char **line)
{
    static char     *str = NULL;
    size_t              i;
    i = 0;
    if (ft_check(fd, &str, line) == 1)
        return (-1);
    str = ft_readallfile(str, fd);
    if (str == NULL)
        return (-1);
    //ft_putstr("je suis avant le while");
    //ft_putchar('\n');
    while (i < ft_strlen(str))
    {
        //ft_putstr("je suis dans le while");
        //ft_putchar('\n');
        if (str[i] == '\n')
        {
            //ft_putstr("je suis dans le if");
            //ft_putchar('\n');
            str[i] = '\0';
            *line = str;
            str = str + i + 1;
            return (1);
        }
        if (str[i + 1] == '\0')
        //test.c == 12345678 puis '\0' rajouté par mon strjoin, donc on check si on est au '\0' final
        {
            //ft_putstr("je suis dans le deuxieme if");
            //ft_putchar('\n');
            *line = str;
            str = str + i + 1;
            //retirer le +1 si ca deconne
            return (1);
        }
        i++;
    }
    //ft_putstr("je suis après le while");
    //ft_putchar('\n');
    *line = ft_strdup("");
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
	char	*buf;
    //mon fd est > 0 mais a été fermé, check est sensé renvoyer 1 ! comment reperer un fd fermé ?

	if (fd < 0 || !line || read(fd, buf, 0) == -1 )
		return (1);
	return (0);
}