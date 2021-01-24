/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:02:22 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/10 03:13:02 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int					cmpnums(int a, int b, int c)
{
	int min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

void				maxlen(t_spot **map, int x, int y)
{
	if (map[x][y].thing == g_map_inf.blank)
	{
		if (x == 0 || y == 0)
			map[x][y].score = 1;
		else
			map[x][y].score = cmpnums(map[x - 1][y].score,
				map[x][y - 1].score, map[x - 1][y - 1].score) + 1;
	}
	else if (map[x][y].thing == g_map_inf.obstacle)
		map[x][y].score = 0;
}

t_max_square		findmaxsquare(t_spot **map)
{
	int				row;
	int				col;
	t_max_square	max_sqr;

	max_sqr.len = 0;
	max_sqr.x = 0;
	max_sqr.y = 0;
	row = 0;
	while (row < g_map_inf.ylen)
	{
		col = 0;
		while (col < g_map_inf.xlen)
		{
			maxlen(map, row, col);
			if (map[row][col].score > max_sqr.len)
			{
				max_sqr.x = col;
				max_sqr.y = row;
				max_sqr.len = map[row][col].score;
			}
			col += 1;
		}
		row += 1;
	}
	return (max_sqr);
}

void				draw_maxsquare(t_spot **map, t_max_square max_sqr)
{
	int i;
	int j;

	i = max_sqr.y - (max_sqr.len - 1);
	while (i <= max_sqr.y)
	{
		j = max_sqr.x - (max_sqr.len - 1);
		while (j <= max_sqr.x)
		{
			map[i][j].thing = g_map_inf.full;
			j++;
		}
		i++;
	}
}

void				draw_map(t_spot **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_map_inf.ylen)
	{
		j = 0;
		while (j < g_map_inf.xlen)
		{
			write(1, &map[i][j].thing, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
