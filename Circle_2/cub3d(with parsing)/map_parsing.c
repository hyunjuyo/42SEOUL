/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:21:32 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/18 12:06:38 by hyunjuyo         ###   ########.fr       */
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
/*
void	temp_map_info_free(t_game *game)
{
	int	i;
	int	j;
	int	count;

	count = game->conf.map_y;
	i = 0;
	while (i < count)
	{
		free(game->conf.temp_map_addr[i]);
		i++;
	}
}
*/

void	fill_with_spaces(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (i < game->conf.map_y)
	{
		len = ft_strlen(game->conf.temp_map_addr[i]);
		if (len < game->conf.map_x)
		{
			while (len < game->conf.map_x)
			{
				game->conf.temp_map_addr[i][len] = ' ';
				len++;
			}
			game->conf.temp_map_addr[i][len] = '\0';
		}
		i++;
	}
}

void	map_parsing(char *map_file, t_game *game)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
	char	test[MAPX_MAX][MAPY_MAX];

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
	fill_with_spaces(game);
	i = 0;
	while (i < game->conf.map_x)
	{
		j = 0;
		while (j < game->conf.map_y)
		{
			test[i][j] = game->conf.temp_map_addr[game->conf.map_y - 1 - j][i];
			j++;
		}
		i++;
	}
	i = -1;
	while (++i < game->conf.map_x)
		printf("%s\n", test[i]);
//	temp_map_info_free(game);
	free(line);
	close(fd);
}
