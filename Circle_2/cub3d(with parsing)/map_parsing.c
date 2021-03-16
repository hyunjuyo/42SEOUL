/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:21:32 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/15 18:26:47 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_next_word(char **l_ptr)
{
	char	*w_ptr;
	int		i;

	i = 0;
	while ((*l_ptr)[i] != ' ' && (*l_ptr)[i] != '\0')
		i++;
	if ((*l_ptr)[i] == '\0')
	{
		w_ptr = ft_strdup(*l_ptr);
        *l_ptr += i + 1;
		return (w_ptr);
	}
	(*l_ptr)[i] = '\0';
	w_ptr = ft_strdup(*l_ptr);
	*l_ptr += i + 1;
	i = 0;
	while ((*l_ptr)[i] == ' ')
		i++;
	*l_ptr += i;
	return (w_ptr);
}

char	*join_next_words(char *l_ptr, char *w_ptr, int max_count)
{
	int		i;
	char	*temp1;
	char	*temp2;

	i = 0;
	while (i < max_count)
	{
		temp1 = w_ptr;
		temp2 = get_next_word(&l_ptr);
		w_ptr = ft_strjoin(temp1, temp2);
		free(temp1);
		free(temp2);
		i++;
	}
	return (w_ptr);
}

int		get_rgb_color(char *l_ptr, char *w_ptr)
{
	int		rgb;
	char	**color_info;
	int		num;
	int		i;

	rgb = 0x0;
	w_ptr = join_next_words(l_ptr, w_ptr, 4);
	color_info = ft_split(w_ptr, ',');
	i = 0;
	while (i < 3)
	{
		rgb *= 16 * 16;
		num = ft_atoi(color_info[i]);
		if (!(num >= 0 && num <= 255))
		{
			printf("parsing failed : incorrect RGB color\n");
			printf("Error\n");
			exit(1);
		}
		rgb += num;
	}
	return (rgb);
}

void	check_conf_type_3(char *line, t_game *game, char *l_ptr, char *w_ptr)
{
	if (ft_strncmp(w_ptr, "F", 2) == 0)
    {
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if ((game->conf.floor = get_rgb_color(l_ptr, w_ptr)) != -1)
			game->conf.chk_complete++;
    }
	else if (ft_strncmp(w_ptr, "C", 2) == 0)
    {
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if ((game->conf.floor = get_rgb_color(l_ptr, w_ptr)) != -1)
			game->conf.chk_complete++;
    }
	else if (w_ptr[0] == '1')
	{
        game->conf.map_start = TRUE;
        save_map_info(line, game);
	}
	else
	{
		free(w_ptr);
		printf("parsing failed : incorrect information\n");
		printf("Error\n");
		exit(1);
	}
}

void	check_conf_type_2(char *line, t_game *game, char *l_ptr, char *w_ptr)
{
	if (ft_strncmp(w_ptr, "WE", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.wall_we, w_ptr, PATH_LEN) != 0)
			game->conf.chk_complete++;
	}
	else if (ft_strncmp(w_ptr, "EA", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.wall_ea, w_ptr, PATH_LEN) != 0)
			game->conf.chk_complete++;
	}
	else if (ft_strncmp(w_ptr, "S", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.sprite, w_ptr, PATH_LEN) != 0)
			game->conf.chk_complete++;
	}
	else
		check_conf_type_3(line, game, l_ptr, w_ptr);
}

void	check_conf_type_1(char *line, t_game *game, char *l_ptr, char *w_ptr)
{
	if (ft_strncmp(w_ptr, "R", 2) == 0)
	{
		free(w_ptr);
		if ((game->conf.win_w = ft_atoi(w_ptr = get_next_word(&l_ptr))) != 0)
			game->conf.chk_complete++;
		free(w_ptr);
		if ((game->conf.win_h = ft_atoi(w_ptr = get_next_word(&l_ptr))) != 0)
			game->conf.chk_complete++;
	}
	else if (ft_strncmp(w_ptr, "NO", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.wall_no, w_ptr, PATH_LEN) != 0)
			game->conf.chk_complete++;
	}
	else if (ft_strncmp(w_ptr, "SO", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.wall_so, w_ptr, PATH_LEN) != 0)
			game->conf.chk_complete++;
	}
	else
		check_conf_type_2(line, game, l_ptr, w_ptr);
}

void	save_conf_info(char *line, t_game *game)
{
	char	*l_ptr;
	char	*w_ptr;
    char    *temp;

	if (game->conf.map_start == TRUE)
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
//	printf("conf.win_w : %d\n", game->conf.win_w);
//	printf("conf.win_h : %d\n", game->conf.win_h);
//	printf("conf.wall_no : %s\n", game->conf.wall_no);
//	printf("conf.wall_so : %s\n", game->conf.wall_so);
//	printf("conf.wall_we : %s\n", game->conf.wall_we);
//	printf("conf.wall_ea : %s\n", game->conf.wall_ea);
//	printf("conf.sprite : %s\n", game->conf.sprite);
//	printf("conf.chk_complete : %d\n", game->conf.chk_complete);
//	printf("conf.map_start : %d\n", game->conf.map_start);
	free(w_ptr);
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
	game->conf.map_start = FALSE;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
//		printf("line : %s\n", line);
		save_conf_info(line, game);
		free(line);
	}
	save_conf_info(line, game);
	free(line);
}
