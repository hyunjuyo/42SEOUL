/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:46:14 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/06 12:23:59 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_int_to_char(unsigned char *start, int num)
{
	start[0] = (unsigned char)(num);
	start[1] = (unsigned char)(num >> 8);
	start[2] = (unsigned char)(num >> 16);
	start[3] = (unsigned char)(num >> 24);
}

void	save_header(t_game *game, t_bmp *bmp)
{
	ft_memset(bmp->file_hd, 0, 14);
	bmp->file_hd[0] = 'B';
	bmp->file_hd[1] = 'M';
	assign_int_to_char(&bmp->file_hd[2], bmp->file_size);
	bmp->file_hd[10] = 54;
	ft_memset(bmp->info_hd, 0, 40);
	bmp->info_hd[0] = 40;
	assign_int_to_char(&bmp->info_hd[4], game->conf.win_w);
	assign_int_to_char(&bmp->info_hd[8], game->conf.win_h);
	bmp->info_hd[12] = 1;
	bmp->info_hd[14] = 24;
	write(bmp->fd, bmp->file_hd, 14);
	write(bmp->fd, bmp->info_hd, 40);
}

void	save_img(t_game *game, t_bmp *bmp)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	color;

	i = 0;
	while (i < game->conf.win_h)
	{
		j = 0;
		while (j < game->conf.win_w)
		{
			x = j;
			y = game->conf.win_h - 1 - i;
			color = game->img1.data[y * game->conf.win_w + x];
			write(bmp->fd, &color, 3);
			j++;
		}
		write(bmp->fd, "000", bmp->pad);
		i++;
	}
}

void	save_bmp_file(t_game *game)
{
	t_bmp	bmp;
	int		img_size;

	bmp.pad = (4 - (game->conf.win_w * 3) % 4) % 4;
	img_size = (3 * game->conf.win_w + bmp.pad) * game->conf.win_h;
	bmp.file_size = 14 + 40 + img_size;
	bmp.img = (unsigned char *)ft_calloc(img_size, sizeof(char));
	if ((bmp.fd = open("image.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
	{
		printf("Error\n[bmp]open() failed\n");
		exit(1);
	}
	save_header(game, &bmp);
	save_img(game, &bmp);
	free(bmp.img);
	close(bmp.fd);
}

void	check_saving_bmp_file(t_game *game)
{
	if (game->save_flag && ft_strncmp(game->save_flag, "--save", 7) == 0)
	{
		save_bmp_file(game);
		system("killall afplay");
		exit(0);
	}
	if (game->save_flag && ft_strncmp(game->save_flag, "--save", 7) != 0)
	{
		printf("Error\nincorrect second argument : %s\n", game->save_flag);
		exit(1);
	}
}
