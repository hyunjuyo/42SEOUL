/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:07:04 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/15 17:51:42 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_check(char *line, t_game *game)
{
	int	i;

	if (game->conf.chk_complete < 9)
	{
		printf("map parsing failed : insufficient information\n");
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
}

void	save_map_info(char *line, t_game *game)
{
	error_check(line, game);
	printf("save_map_info process ..ing\n");
}
