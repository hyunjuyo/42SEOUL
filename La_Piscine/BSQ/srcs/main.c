/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:50:43 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/10 08:23:53 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		open_file(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	return (fd);
}

void	mapping(t_spot **map)
{
	draw_maxsquare(map, findmaxsquare(map));
	draw_map(map);
}

void	free_map(t_spot **map)
{
	int i;

	i = 0;
	while (i < g_map_inf.ylen)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int		main(int n, char *file_name[])
{
	int		i;
	int		fd;
	int		flag;
	t_spot	**map;

	i = 0;
	while (++i < n + 1)
	{
		fd = 0;
		flag = 0;
		if (n != 1)
			if (!(fd = open_file(file_name[i++])))
			{
				write(1, "map error\n", 10);
				continue;
			}
		map = read_map(0 + fd, &flag);
		if (flag)
			write(1, "map error\n", 10);
		else
			mapping(map);
		free_map(map);
	}
	return (1);
}
