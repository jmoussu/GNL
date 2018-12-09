/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:03:41 by jmoussu           #+#    #+#             */
/*   Updated: 2018/12/09 18:38:09 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# define BUFF_SIZE 42

typedef struct		s_var
{
	char			buff[BUFF_SIZE + 1];
	int				size;
	int				i;
	char			*ptr;
}					t_var;

int					get_next_line(const int fd, char **line);

#endif
