/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:48:37 by jmoussu           #+#    #+#             */
/*   Updated: 2019/01/28 15:20:59 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

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
	while ((retGNL = get_next_line(fd, &line)) != 0)
	{
		ft_putnbr(retGNL);
		ft_putchar('\t');
		ft_putstr(line);
		free(line);
		ft_putchar('\n');
		i++;
	}
	ft_putnbr(retGNL);
	ft_putstr("\nBUFF_SIZE = ");
	ft_putnbr(BUFF_SIZE);
	if (close(fd) == -1)
	{
		ft_putstr("Close Fail.\n");
		return (1);
	}
	return (0);
}
