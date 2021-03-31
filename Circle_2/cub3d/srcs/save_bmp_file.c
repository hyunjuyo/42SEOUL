/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:46:14 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/31 13:54:09 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct	s_bmp
{
	int				fd;
	int				pad;
	int				file_size;
	unsigned char	file_hd[14];
	unsigned char	info_hd[40];
	unsigned char	*img;
}				t_bmp;

void	assign_int_to_char(unsigned char *start, int num)
{
	printf("num : %d\n", num);
	start[0] = (unsigned char)(num);
	start[1] = (unsigned char)(num >> 8);
	start[2] = (unsigned char)(num >> 16);
	start[3] = (unsigned char)(num >> 24);
	printf("num : %d\nnum >> 8 : %d\nnum >> 16 : %d\nnum >> 24 : %d\n", (unsigned char)(num), (unsigned char)(num >> 8), (unsigned char)(num >> 16), (unsigned char)(num >> 24));
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
//	ft_memset(bmp->pad, 0, 3); // check
	write(bmp->fd, bmp->file_hd, 14);
	write(bmp->fd, bmp->info_hd, 40);
}
/*
void	save_rgb_to_bmp(unsigned char *addr, int i, int j, t_game *game, t_bmp *bmp)
{
	int	color;
	int	r;
	int	g;
	int	b;

	color = game->img1.data[i * game->conf.win_w + j];
	printf("game color : %#x\n", color); // test
	b = color % (0x10 * 0x10);
	color = color / (0x10 * 0x10);
	g = color % (0x10 * 0x10);
	color = color / (0x10 * 0x10);
	r = color % (0x10 * 0x10);
	addr[0] = (unsigned char)b;
	printf("bmp color : %#x\n", (int)addr[0]);
	addr[1] = (unsigned char)g;
	printf("bmp color : %#x\n", (int)addr[1]);
	addr[2] = (unsigned char)r;
	printf("bmp color : %#x\n", (int)addr[2]);i
}
*/
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
//	int		i;

	bmp.pad = (4 - (game->conf.win_w * 3) % 4) % 4;
	img_size = (3 * game->conf.win_w + bmp.pad) * game->conf.win_h;
	bmp.file_size = 14 + 40 + img_size;
	printf("file_size : %d, img_size : %d\n", bmp.file_size, img_size);
	bmp.img = (unsigned char *)ft_calloc(img_size, sizeof(char));
	if ((bmp.fd = open("image.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
	{
		printf("Error\n[bmp]open() failed\n");
		exit(1);
	}
	save_header(game, &bmp);
//	i = 0;
//	while (i < 14)
//	{
//		printf("%c", bmp.file_hd[i]);
//		i++;
//	}
//	printf("\n");
//	i = 0;
//	while (i < 40)
//	{
//		printf("%c", bmp.info_hd[i]);
//		i++;
//	}
//	printf("\n");
	save_img(game, &bmp);
	free(bmp.img);
	close(bmp.fd);
}
