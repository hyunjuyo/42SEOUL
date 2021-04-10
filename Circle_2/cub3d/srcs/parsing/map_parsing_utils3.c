/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:47:26 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/10 13:49:06 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	do_check(t_game *game, char *img_path, char *type)
{
	t_img	temp;

	temp.img = mlx_xpm_file_to_image(game->mlx, img_path, &temp.width,
			&temp.height);
	if (!temp.img)
	{
		printf("Error\n[%s]mlx_xpm_file_to_image() failed\n", type);
		exit(1);
	}
}

void	img_file_open_check(t_game *game)
{
	char	*img_path;

	img_path = game->conf.wall_no;
	do_check(game, img_path, "NO");
	img_path = game->conf.wall_so;
	do_check(game, img_path, "SO");
	img_path = game->conf.wall_we;
	do_check(game, img_path, "WE");
	img_path = game->conf.wall_ea;
	do_check(game, img_path, "EA");
	img_path = game->conf.sprite[0];
	do_check(game, img_path, "S");
}
