/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:11:39 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/10 08:33:14 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_atoi(char *nstr)
{
	int nbr;

	nbr = 0;
	if (*nstr == 0 || nstr[0] <= '0' || '9' < nstr[0])
		return (0);
	while (*nstr)
	{
		nbr *= 10;
		nbr += (*nstr - '0');
		++nstr;
	}
	return (nbr);
}

int	is_validinfo(char *th)
{
	if (g_map_inf.blank == th[1] || th[1] == th[2] || th[2] == g_map_inf.blank
			|| g_map_inf.blank == 0 || th[1] == 0 || th[2] == 0
			|| g_map_inf.blank == '\n' || th[1] == '\n' || th[2] == '\n')
		return (1);
	g_map_inf.obstacle = th[1];
	g_map_inf.full = th[2];
	g_map_inf.xlen = 1;
	g_len = 5;
	return (0);
}

int	read_map_info(int fd, int *flag)
{
	char	ylen_ch[6];
	char	th[3];
	int		idx;
	char	ch;

	idx = 0;
	while (read(fd, &ch, 1) && '0' <= ch && ch <= '9')
	{
		ylen_ch[idx++] = ch;
		continue;
	}
	ylen_ch[idx] = 0;
	idx = 1;
	g_map_inf.blank = ch;
	while (read(fd, &ch, 1))
	{
		if (idx < 3)
			th[idx++] = ch;
		if (ch == '\n' || g_map_inf.blank == '\n')
			break ;
	}
	if (is_validinfo(th) || !(g_map_inf.ylen = ft_atoi(ylen_ch)))
		*flag = 1;
	return (1);
}
