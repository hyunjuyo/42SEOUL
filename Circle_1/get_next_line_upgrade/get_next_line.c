/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 17:52:32 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/01/31 22:54:36 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_linefeed(int fd, char *storage[], char *buf)
{
	int		i;
	char	*temp;

	if (!storage[fd])
		storage[fd] = ft_strdup("");
	temp = storage[fd];
	storage[fd] = ft_strjoin(storage[fd], buf);
	free(temp);
	i = -1;
	while (storage[fd][++i])
	{
		if (storage[fd][i] == '\n')
			return (i);
	}
	return (-1);
}

void	save_line(int fd, char *storage[], int i, char **line)
{
	storage[fd][i] = '\0';
	*line = storage[fd];
	storage[fd] = ft_strdup(&storage[fd][i + 1]);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*storage[256];
	int			read_value;
	int			i;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((read_value = read(fd, buf, BUFFER_SIZE)) == -1)
		return (-1);
	buf[read_value] = '\0';
	while ((i = find_linefeed(fd, storage, buf)) == -1 && read_value > 0)
	{
		read_value = read(fd, buf, BUFFER_SIZE);
		buf[read_value] = '\0';
	}
	save_line(fd, storage, i, line);
	if (i == -1 && read_value == 0)
	{
		free(storage[fd]);
		storage[fd] = 0;
		return (0);
	}
	return (1);
}

int		main(void)
{
	int		fd;
	char	*line;
	int		result;

	if ((fd = open("test1.txt", O_RDONLY)) == -1)
		return (0);
	while ((result = get_next_line(fd, &line)) > 0)
	{
		printf("%d | %s\n", result, line);
		free(line);
	}
	printf("%d | %s\n", result, line);
	free(line);
	close(fd);
	return (0);
}
