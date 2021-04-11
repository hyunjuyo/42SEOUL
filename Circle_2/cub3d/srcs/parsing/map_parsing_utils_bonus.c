/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:17:49 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/11 16:23:38 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	save_conf_resolution(t_game *game, char **l_ptr, char *w_ptr, char type)
{
	if (type == 'w')
	{
		w_ptr = get_next_word(l_ptr);
		if ((game->conf.win_w = atoi_n_check(w_ptr, "R")) != 0)
		{
			if (game->conf.win_w > game->conf.display_w)
				game->conf.win_w = game->conf.display_w;
			overlap_check(game, "Rw");
		}
		free(w_ptr);
	}
	else
	{
		w_ptr = get_next_word(l_ptr);
		if ((game->conf.win_h = atoi_n_check(w_ptr, "R")) != 0)
		{
			if (game->conf.win_h > game->conf.display_h)
				game->conf.win_h = game->conf.display_h;
			overlap_check(game, "Rh");
		}
		free(w_ptr);
	}
}

void	save_player_info(t_game *game, int i, int j, char c)
{
	if (game->player.x != 0.0 || game->player.y != 0.0)
	{
		printf("Error\nMap parsing failed : too many player's position(s)\n");
		exit(1);
	}
	game->player.x = (double)i + 0.5;
	game->player.y = (double)j + 0.5;
	if (c == 'N')
		game->player.th = deg_to_rad(90.0, 1);
	else if (c == 'S')
		game->player.th = deg_to_rad(270.0, 1);
	else if (c == 'W')
		game->player.th = deg_to_rad(180.0, 1);
	else
		game->player.th = deg_to_rad(0.0, 1);
}

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
		*l_ptr += i;
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

char	*join_next_words(char **l_ptr, char *w_ptr, int max_count)
{
	int		i;
	char	*temp1;
	char	*temp2;

	i = 0;
	while (i < max_count)
	{
		temp1 = w_ptr;
		temp2 = get_next_word(l_ptr);
		w_ptr = ft_strjoin(temp1, temp2);
		free(temp1);
		free(temp2);
		i++;
	}
	return (w_ptr);
}

int		get_rgb_color(char **l_ptr, char *w_ptr)
{
	int		rgb;
	char	**color_info;
	int		num;
	int		i;

	w_ptr = join_next_words(l_ptr, w_ptr, 4);
	rgb = 0x0;
	color_info = ft_split(w_ptr, ',');
	free(w_ptr);
	i = -1;
	while (++i < 3)
	{
		rgb *= 0x10 * 0x10;
		if (!color_info[i])
			print_parsing_error("C/F", "incorrect information");
		num = atoi_n_check(color_info[i], "C/F");
		free(color_info[i]);
		check_rgb_range(num);
		rgb += num;
	}
	free(color_info);
	return (rgb);
}
