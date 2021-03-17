/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:21:32 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/17 13:13:56 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_conf_info(char *line, t_game *game)
{
	char	*l_ptr;
	char	*w_ptr;
    char    *temp;

	if (game->conf.map_lines > 0)
    {
		save_map_info(line, game);
        return ;
    }
	l_ptr = ft_strtrim(line, " ");
    temp = l_ptr;
	if (ft_strlen(l_ptr) == 0)
	{
		free(temp);
		return ;
	}
	w_ptr = get_next_word(&l_ptr);
	check_conf_type_1(line, game, l_ptr, w_ptr);
	printf("conf.win_w : %d\n", game->conf.win_w); //
	printf("conf.win_h : %d\n", game->conf.win_h); //
	printf("conf.wall_no : %s\n", game->conf.wall_no); //
	printf("conf.wall_so : %s\n", game->conf.wall_so); //
	printf("conf.wall_we : %s\n", game->conf.wall_we); //
	printf("conf.wall_ea : %s\n", game->conf.wall_ea); //
	printf("conf.sprite : %s\n", game->conf.sprite); //
	printf("conf.chk_complete : %d\n", game->conf.chk_complete); //
	printf("conf.map_lines : %d\n", game->conf.map_lines); //
	free(temp);
}

void	map_parsing(char *map_file, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	if ((fd = open(map_file, O_RDONLY)) == -1)
	{
		printf("open() failed\n");
		printf("Error\n");
		exit(1);
	}
    game->conf.chk_complete = 0;
	game->conf.map_lines = 0;
	game->conf.map_x = 0;
	game->conf.map_y = 0;
	game->conf.ceil = -1;
	game->conf.floor = -1;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		printf("line : %s\n", line); //
		save_conf_info(line, game);
		free(line);
	}
	save_conf_info(line, game);
	free(line);
}
