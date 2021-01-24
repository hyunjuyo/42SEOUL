/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:39:06 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/01/09 20:08:21 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_cuts_to_line(int fd, char **line, char **bufdup, int *next_chk)
{
	int	i;

	i = 0;
	while (bufdup[fd][i] != '\0' && bufdup[fd][i] != '\n')
		i++;
	if (bufdup[fd][i] == '\n')
	{
		bufdup[fd][i] = '\0';
		*line = bufdup[fd];
		bufdup[fd] = ft_strdup(bufdup[fd] + i + 1);
		if (bufdup[fd][0] == '\0')
			*next_chk = 0;
		else
			*next_chk = 1;
		return ;
	}
	*next_chk = 2;
}

static int	ft_read_to_bufdup(int fd, char *buf, char **bufdup)
{
	int		read_value;
	char	*ptr;

	if ((read_value = read(fd, buf, BUFFER_SIZE)) == -1)
		return (read_value);
	buf[read_value] = '\0';
	if (!bufdup[fd])
		bufdup[fd] = ft_strdup("");
	ptr = bufdup[fd];
	if (!(bufdup[fd] = ft_strjoin(bufdup[fd], buf)))
		return (-1);
	free(ptr);
	return (read_value);
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*bufdup[256];
	int			read_value;
	int			next_chk;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	read_value = 1;
	if (!bufdup[fd])
	{
		if ((read_value = ft_read_to_bufdup(fd, buf, bufdup)) == -1)
			return (-1);
	}
	while (read_value > 0)
	{
		ft_cuts_to_line(fd, line, bufdup, &next_chk);
		if ((read_value = ft_read_to_bufdup(fd, buf, bufdup)) == -1)
			return (-1);
		if (next_chk == 0 || next_chk == 1)
			return (1);
	}
	*line = bufdup[fd];
	bufdup[fd] = 0;
	return (0);
}
