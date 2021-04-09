/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_info_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:07:04 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/09 17:50:12 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		error_check(char *line, t_game *game)
{
	int	i;

	if (game->conf.chk_complete < 11)
	{
		printf("Error\nParsing failed : insufficient info before map\n");
		exit(1);
	}
	i = 0;
	while (line[i] && (line[i] == '1' || line[i] == '2' || line[i] == '0'
				|| line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
				|| line[i] == 'E' || line[i] == ' ' || line[i] == '3'
				|| line[i] == '4'))
		i++;
	if (i == 0 || i != (int)ft_strlen(line))
	{
		if (i == 0)
			printf("Error\nMap parsing failed : one or more empty line(s)\n");
		else
			printf("Error\nMap parsing failed : '%c' is an impossible \
character\n", line[i]);
		exit(1);
	}
	return (0);
}

void	save_map_info(char *line, t_game *game)
{
	int			x_len;
	static char	*map_info[MAPY_MAX];

	game->conf.temp_map_addr = map_info;
	game->conf.chk_complete = game->conf.check.rw + game->conf.check.rh +
		game->conf.check.no + game->conf.check.so + game->conf.check.we +
		game->conf.check.ea + game->conf.check.s + game->conf.check.s2 +
		game->conf.check.s3 + game->conf.check.c + game->conf.check.f;
	if (error_check(line, game) == 0)
		game->conf.map_lines++;
	game->conf.map_y = game->conf.map_lines;
	if ((x_len = ft_strlen(line)) > game->conf.map_x)
		game->conf.map_x = x_len;
	if (!(map_info[game->conf.map_y - 1] = (char *)malloc(sizeof(char) *
					(x_len + 1))))
	{
		printf("Error\nMap parsing failed : malloc() failed\n");
		exit(1);
	}
	ft_strlcpy(map_info[game->conf.map_y - 1], line, x_len + 1);
}
