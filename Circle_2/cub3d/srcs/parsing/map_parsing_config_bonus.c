/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_config_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:03:03 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/09 18:26:32 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_conf_type_5(char *line, t_game *game, char *l_ptr, char *w_ptr)
{
	if (ft_strncmp(w_ptr, "S2", 3) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.sprite[1], w_ptr, PATH_LEN) != 0)
			overlap_check(game, "S2");
		free(w_ptr);
		if (*l_ptr != '\0')
			print_parsing_error("S2", "too many informations");
	}
	else if (ft_strncmp(w_ptr, "S3", 3) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.sprite[2], w_ptr, PATH_LEN) != 0)
			overlap_check(game, "S3");
		free(w_ptr);
		if (*l_ptr != '\0')
			print_parsing_error("S3", "too many informations");
	}
	else
		check_conf_type_6(line, game, w_ptr);
}

void	check_conf_type_4(char *line, t_game *game, char *l_ptr, char *w_ptr)
{
	if (ft_strncmp(w_ptr, "C", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if ((game->conf.ceil = get_rgb_color(&l_ptr, w_ptr)) > -1)
			overlap_check(game, "C");
		if (*l_ptr != '\0')
			print_parsing_error("C", "too many informations");
	}
	else if (ft_strncmp(w_ptr, "F", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if ((game->conf.floor = get_rgb_color(&l_ptr, w_ptr)) > -1)
			overlap_check(game, "F");
		if (*l_ptr != '\0')
			print_parsing_error("F", "too many informations");
	}
	else
		check_conf_type_5(line, game, l_ptr, w_ptr);
}

void	check_conf_type_3(char *line, t_game *game, char *l_ptr, char *w_ptr)
{
	if (ft_strncmp(w_ptr, "EA", 3) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.wall_ea, w_ptr, PATH_LEN) != 0)
			overlap_check(game, "EA");
		free(w_ptr);
		if (*l_ptr != '\0')
			print_parsing_error("EA", "too many informations");
	}
	else if (ft_strncmp(w_ptr, "S", 2) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.sprite[0], w_ptr, PATH_LEN) != 0)
			overlap_check(game, "S");
		free(w_ptr);
		if (*l_ptr != '\0')
			print_parsing_error("S", "too many informations");
	}
	else
		check_conf_type_4(line, game, l_ptr, w_ptr);
}

void	check_conf_type_2(char *line, t_game *game, char *l_ptr, char *w_ptr)
{
	if (ft_strncmp(w_ptr, "SO", 3) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.wall_so, w_ptr, PATH_LEN) != 0)
			overlap_check(game, "SO");
		free(w_ptr);
		if (*l_ptr != '\0')
			print_parsing_error("SO", "too many informations");
	}
	else if (ft_strncmp(w_ptr, "WE", 3) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.wall_we, w_ptr, PATH_LEN) != 0)
			overlap_check(game, "WE");
		free(w_ptr);
		if (*l_ptr != '\0')
			print_parsing_error("WE", "too many informations");
	}
	else
		check_conf_type_3(line, game, l_ptr, w_ptr);
}

void	check_conf_type_1(char *line, t_game *game, char *l_ptr, char *w_ptr)
{
	if (ft_strncmp(w_ptr, "R", 2) == 0)
	{
		free(w_ptr);
		save_conf_resolution(game, &l_ptr, w_ptr, 'w');
		save_conf_resolution(game, &l_ptr, w_ptr, 'h');
		if (*l_ptr != '\0')
			print_parsing_error("R", "too many informations");
	}
	else if (ft_strncmp(w_ptr, "NO", 3) == 0)
	{
		free(w_ptr);
		w_ptr = get_next_word(&l_ptr);
		if (ft_strlcpy(game->conf.wall_no, w_ptr, PATH_LEN) != 0)
			overlap_check(game, "NO");
		free(w_ptr);
		if (*l_ptr != '\0')
			print_parsing_error("NO", "too many informations");
	}
	else
		check_conf_type_2(line, game, l_ptr, w_ptr);
}
