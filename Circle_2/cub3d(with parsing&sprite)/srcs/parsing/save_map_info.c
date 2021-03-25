/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:07:04 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/22 13:40:13 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		error_check(char *line, t_game *game)
{
	int	i;

	if (game->conf.chk_complete < 9)
	{
		printf("Parsing failed : insufficient info. before map content\n");
		printf("Error\n");
		exit(1);
	}
	i = 0;
	while (line[i] && (line[i] == '1' || line[i] == '2' || line[i] == '0'
				|| line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
				|| line[i] == 'E' || line[i] == ' '))
		i++;
	if (i == 0 || i != (int)ft_strlen(line))
	{
		if (i == 0)
			printf("Map parsing failed : one or more empty line(s)\n");
		else
			printf("Map parsing failed : '%c' is an impossible character\n",
					line[i]);
		printf("Error\n");
		exit(1);
	}
	return (0);
}

void	save_map_info(char *line, t_game *game)
{
	int			i;
	int			x_len;
	static char	*map_info[MAPY_MAX];

	game->conf.temp_map_addr = map_info; // for free() after save_map_info()
	if (error_check(line, game) == 0)
		game->conf.map_lines++;
	game->conf.map_y = game->conf.map_lines;
	if ((x_len = ft_strlen(line)) > game->conf.map_x)
		game->conf.map_x = x_len;
	if (!(map_info[game->conf.map_y - 1] = (char *)malloc(sizeof(char) *
					(x_len + 1))))
	{
		printf("Map parsing failed : malloc() failed\n");
		printf("Error\n");
		exit(1);
	}
	ft_strlcpy(map_info[game->conf.map_y - 1], line, x_len + 1);
	printf("MAP_X : %d, MAP_Y : %d\n", game->conf.map_x, game->conf.map_y); // test
	i = -1; // test
	while (++i < game->conf.map_y) // test
		printf("%s\n", map_info[i]); // test
	printf("save_map_info process ..ing\n");
}
