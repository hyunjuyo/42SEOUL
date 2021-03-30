

#include "cub3d.h"

typedef struct	s_bmp
{
	int				fd;
	unsigned char	file_hd[14];
	unsigned char	info_hd[40];
	unsigned char	*img;
	int				file_size;
}				t_bmp;

void	assign_int_to_char(unsigned char *header, int num)
{
	header[0] = (unsigned char)(num);
	header[1] = (unsigned char)(num >> 8);
	header[2] = (unsigned char)(num >> 16);
	header[3] = (unsigned char)(num >> 24);
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
//	ft_memset(bmp->pad, 0, 3); // (?)
	write(bmp->fd, bmp->file_hd, 14);
	write(bmp->fd, bmp->info_hd, 40);

}

void	save_img(t_game *game, t_bmp *bmp)
{




}

void	bmp_file(t_game *game)
{
	t_bmp			bmp;
	int				img_size;

	img_size = 3 * game->conf.win_w * game->conf.win_h;
	bmp.file_size = 14 + 40 + img_size;
	bmp.img = (unsigned char *)ft_calloc(img_size, sizeof(unsigned char));
	bmp.fd = open(); // check
	save_header(game, &bmp);
	save_img(game, &bmp);
	free(bmp.img);
	close(bmp.fd);
}
