/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_config.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:03:03 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/05 19:04:38 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_conf_type_5(char *line, t_game *game, char *l_ptr, char *w_ptr)
{
	if (ft_strncmp(w_ptr, "F", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if ((game->conf.floor = get_rgb_color(l_ptr, w_ptr)) > -1)
			game->conf.chk_complete++;
	}
	else if (w_ptr[0] == '1')
	{
		free(w_ptr);
		save_map_info(line, game);
	}
	else
	{
		free(w_ptr);
		printf("Error\nParsing failed : incorrect information\n");
		exit(1);
	}
}

void	check_conf_type_4(char *line, t_game *game, char *l_ptr, char *w_ptr)
{
	if (ft_strncmp(w_ptr, "S", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.sprite[0], w_ptr, PATH_LEN) != 0)
			game->conf.chk_complete++;
		free(w_ptr);
	}
	else if (ft_strncmp(w_ptr, "C", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if ((game->conf.ceil = get_rgb_color(l_ptr, w_ptr)) > -1)
			game->conf.chk_complete++;
	}
	else
		check_conf_type_5(line, game, l_ptr, w_ptr);
}

void	check_conf_type_3(char *line, t_game *game, char *l_ptr, char *w_ptr)
{
	if (ft_strncmp(w_ptr, "WE", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.wall_we, w_ptr, PATH_LEN) != 0)
			game->conf.chk_complete++;
		free(w_ptr);
	}
	else if (ft_strncmp(w_ptr, "EA", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.wall_ea, w_ptr, PATH_LEN) != 0)
			game->conf.chk_complete++;
		free(w_ptr);
	}
	else
		check_conf_type_4(line, game, l_ptr, w_ptr);
}

void	check_conf_type_2(char *line, t_game *game, char *l_ptr, char *w_ptr)
{
	if (ft_strncmp(w_ptr, "NO", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.wall_no, w_ptr, PATH_LEN) != 0)
			game->conf.chk_complete++;
		free(w_ptr);
	}
	else if (ft_strncmp(w_ptr, "SO", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.wall_so, w_ptr, PATH_LEN) != 0)
			game->conf.chk_complete++;
		free(w_ptr);
	}
	else
		check_conf_type_3(line, game, l_ptr, w_ptr);
}

void	check_conf_type_1(char *line, t_game *game, char *l_ptr, char *w_ptr)
{
	if (ft_strncmp(w_ptr, "R", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if ((game->conf.win_w = ft_atoi(w_ptr)) != 0)
		{
			if (game->conf.win_w > game->conf.display_w)
				game->conf.win_w = game->conf.display_w;
			game->conf.chk_complete++;
		}
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if ((game->conf.win_h = ft_atoi(w_ptr)) != 0)
		{
			if (game->conf.win_h > game->conf.display_h)
				game->conf.win_h = game->conf.display_h;
			game->conf.chk_complete++;
		}
		free(w_ptr);
	}
	else
		check_conf_type_2(line, game, l_ptr, w_ptr);
}
