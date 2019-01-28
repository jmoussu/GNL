/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:02:59 by jmoussu           #+#    #+#             */
/*   Updated: 2018/12/03 14:57:49 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_error(int fd, char **line)
{
	char	buf[BUFF_SIZE];
	//mon fd est > 0 mais a été fermé, check est sensé renvoyer 1 ! comment reperer un fd fermé ?

	if (fd < 0 || !line || read(fd, buf, 0) == -1 )
		return (1);
	// if (!*str)
	// 	if (!(*str = (char*)malloc(BUFF_SIZE + 1)))
	// 		return (1);
	return (0);
}

char	*readfile(char *str, int fd)
{
	int		size;
	char	buffer[BUFF_SIZE + 1];

	//ft_putstr("salut je read");
	while ((size = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		//ft_putstr("salut je WHILE");
		buffer[size] = '\0';
		if (!(str = ft_strjoinfree(str, buffer, 1)))
			return (NULL);
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	size_t		i;
	//static int	g = 0;

	i = 0;
	if (!(str))
		if (!(str = ft_strdup("")))
			return (-1);
	if (ft_error(fd, line) == 1)
		return (-1);
	if (ft_strcmp(str, "") == 0)
		if (!(str = readfile(str, fd)))
			return (-1);
	while (str && *str && i < ft_strlen(str))
	{
		if (str == NULL)
			return (-1);
		if(str[i] == '\n')
		{
			str[i] = 0;
			*line = str;
			str = str + i + 1;
			// ft_putstr("retour v1");
			return (1);
		}
		i++;
	}
	if (str && ft_strlen(str) > 0)
	{
		*line = str;
		str = str + i;
		// ft_putstr("retour v2");
		return (1);
	}
	return (0);
}

/*
int		main(int argc, char **argv)
{
	int		retGNL;
	int		fd;
	char	*line;
	int i;
	line = NULL;
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
	while (i < 1000 && (retGNL = get_next_line(fd, &line)) != 0)
	{
		ft_putnbr(retGNL);
		ft_putchar('\t');
		ft_putstr(line);
		ft_putchar('\n');
		i++;
	}
	ft_putnbr(get_next_line(fd, &line));
	ft_putstr("\n BUFF_SIZE = ");
	ft_putnbr(BUFF_SIZE);
	if (close(fd) == -1)
	{
		ft_putstr("Close Fail.\n");
		return (1);
	}
	return (0);
}


# include <stdio.h>

int     main(int ac, char **av, char **env)
{
	char 	*line;
	int		out;
	int		p[2];
	char 	*str;
	int		gnl_ret;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	write(1, str, strlen(str));
	close(p[1]);
	dup2(out, 1);
	gnl_ret = get_next_line(p[0], &line);
	printf("lolrofl : %d - line: %s\n", strcmp(line, str) == 0, line);
	gnl_ret = get_next_line(p[0], &line);
	printf("lolrofl : %d - line: %s\n", strcmp(line, str) == 0, line);
	gnl_ret = get_next_line(p[0], &line);
	printf("lolrofl : %d - line: %s\n", strcmp(line, str) == 0, line);
	//mt_assert(gnl_ret == 0 || gnl_ret == 1);
}

*/
