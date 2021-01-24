/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:43:50 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/10 08:39:10 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_spot	*copy_row(t_spot *row)
{
	t_spot	*temp;
	int		i;

	i = 0;
	temp = (t_spot *)malloc(sizeof(t_spot) * (g_len * 10));
	if (!temp)
		exit(0);
	while (i < g_len)
	{
		temp[i].thing = row[i].thing;
		i++;
	}
	g_len *= 10;
	free(row);
	return (temp);
}

t_spot	*chk_x(char *ch, t_spot *row, int *idx, int *flag)
{
	if (*ch != g_map_inf.blank && *ch != g_map_inf.obstacle && *ch != '\n')
		*flag = 1;
	if (*ch != '\n')
	{
		if (*idx + 1 == g_len)
			row = copy_row(row);
		row[*idx].thing = *ch;
		*idx += 1;
	}
	return (row);
}

int	chk_len(char *ch, int *idx, int j, int *flag)
{
	if (*ch == '\n')
	{
		if (g_map_inf.xlen != *idx && j > 0)
			*flag = 1;
		else
			g_map_inf.xlen = *idx;
		return (1);
	}
	return (0);
}

t_spot	**read_map(int fd, int *flag)
{
	char		ch;
	int			idx;
	int			j;
	t_spot		*row;
	t_spot		**map;

	j = -1;
	read_map_info(fd, flag);
	if (!(map = (t_spot**)malloc(sizeof(t_spot *) * g_map_inf.ylen)))
		exit(0);
	while (++j < g_map_inf.ylen)
	{
		idx = 0;
		if (!(row = (t_spot *)malloc(sizeof(t_spot) * g_len)))
			exit(0);
		while ((read(fd, &ch, 1)))
			if (!(row = chk_x(&ch, row, &idx, flag)))
				*flag = 1;
			else if (chk_len(&ch, &idx, j, flag))
				break ;
		map[j] = row;
	}
	close(fd);
	return (map);
}
