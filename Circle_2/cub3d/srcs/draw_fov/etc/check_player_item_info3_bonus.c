/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_item_info3_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:59:36 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/11 17:16:21 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*get_ani_img_path(t_game *game)
{
	char	*img_path;
	char	*temp_idx;
	char	*temp_ptr;

	temp_idx = ft_itoa(game->player.get_map);
	temp_ptr = ft_strjoin("./textures/animation/map_ani_", temp_idx);
	free(temp_idx);
	img_path = ft_strjoin(temp_ptr, ".xpm");
	free(temp_ptr);
	return (img_path);
}

void	draw_one_animation_image(t_game *game)
{
	int		i;
	int		j;
	double	w_ratio;
	double	h_ratio;
	int		color;

	w_ratio = (double)game->player.ani.width / (double)game->conf.win_w;
	h_ratio = (double)game->player.ani.height / (double)game->conf.win_h;
	j = 0;
	while (j < game->conf.win_h)
	{
		i = 0;
		while (i < game->conf.win_w)
		{
			color = game->player.ani.data[(int)(j * h_ratio) *
				game->player.ani.width + (int)(i * w_ratio)];
			if (check_color_area(color, BLUE, 0x87) != 111)
				game->img1.data[j * game->conf.win_w + i] = color;
			i++;
		}
		j++;
	}
}

void	item_animation(t_game *game)
{
	char	*img_path;

	img_path = get_ani_img_path(game);
	if (!(game->player.ani.img = mlx_xpm_file_to_image(game->mlx, img_path,
			&game->player.ani.width, &game->player.ani.height)))
	{
		printf("Error\n[map_ani]mlx_xpm_file_to_image() failed\n");
		waitpid(game->pid, &game->pid_status, WNOHANG);
		if (game->pid_status == -1)
			system("killall afplay");
		exit(1);
	}
	game->player.ani.data = (int *)mlx_get_data_addr(game->player.ani.img,
			&game->player.ani.bpp, &game->player.ani.size_l,
			&game->player.ani.endian);
	draw_one_animation_image(game);
	game->player.get_map++;
	free(img_path);
	if (game->player.get_map == 28)
	{
		game->player.get_map = 0;
		game->player.item[0] = 1;
	}
}
