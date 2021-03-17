/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:07:04 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/17 13:28:39 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		error_check(char *line, t_game *game)
{
	int	i;

	if (game->conf.chk_complete < 9)
	{
		printf("parsing failed : insufficient information\n");
		printf("Error\n");
		exit(1);
	}
	i = 0;
	while (line[i] && (line[i] == '1' || line[i] == '2' || line[i] == '0'
				|| line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
				|| line[i] == 'E' || line[i] == ' '))
		i++;
	if (i != (int)ft_strlen(line))
	{
		printf("map parsing failed : '%c' is impossible character\n", line[i]);
		printf("Error\n");
		exit(1);
	}
	return (0);
}

void	save_map_info(char *line, t_game *game)
{
	int		i;
	int		x_len;
	int		y_len;
	char	**ptr;

	if (error_check(line, game) == 0)
		game->conf.map_lines++;
	y_len = game->conf.map_lines;
	if ((x_len = ft_strlen(line)) > game->conf.map_x)
		game->conf.map_x = x_len;
	if (!(ptr = (char *)malloc(sizeof(char) * (x_len + 1))))
	{
		printf("map parsing failed : malloc() failed\n", line[i]);
		printf("Error\n");
		exit(1);
	}

	printf("save_map_info process ..ing\n");
}
