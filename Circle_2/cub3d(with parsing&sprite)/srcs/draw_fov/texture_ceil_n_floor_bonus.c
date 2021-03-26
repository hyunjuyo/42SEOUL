




#include "cub3d.h"


double	get_min_dist_in_fov(t_game *game)
{
	double	fov_vert;
	double	min_dist;
	double	half_wall_len;

	fov_vert = deg_to_rad(FOV * game->conf.win_h / game->conf.won_w, 0);
	half_wall_len = 0.5;
	min_dist = half_wall_len / tan(fov_vert / 2.0);
	return (min_dist);
}

int		get_ceil_texture(double dist, t_game *game, t_img *c_img)
{
	int	color;


	return (color);}
}

void	draw_one_vert_ceil_line(int i, int wall_len, double min_dist, t_game *game, t_img *c_img)
{
	int		j;
	int		area_len;
	double	h;
	double	dist;

	area_len = (game->conf.win_h - wall_len) / 2;
	j = 0;
	while (j < area_len)
	{
		h = j / game->conf.win_h;
		dist = min_dist / (1 - 2 * h);
		game->img1.data[j * game->conf.win_w + i]
			= get_ceil_texture(dist, game, c_img);
		j++;
	}

}

void	texture_ceil_n_floor(t_game *game)
{
	int		i;
	int		wall_len;
	double	min_dist;
	t_img	c_img;
	t_img	f_img;

	if (!(c_img.img = mlx_xpm_file_to_image(game->mlx, "./textures/ceil.xpm",
					&c_img.width, &c_img.height)))
		printf("[ceil]mlx_xpm_file_to_image() failed\nError\n");
	c_img.data = (int *)mlx_get_data_addr(c_img.img, &c_img.bpp, &c_img.size_l,
			&c_img.endian);
	if (!(f_img.img = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
					&f_img.width, &f_img.height)))
		printf("[floor]mlx_xpm_file_to_image() failed\nError\n");
	f_img.data = (int *)mlx_get_data_addr(f_img.img, &f_img.bpp, &f_img.size_l,
			&f_img.endian);
	min_dist = get_min_dist_in_fov(game);
	i = 0;
	while (i < game->conf.win_w)
	{
		wall_len = get_vert_line_length(game->wall.dist[i], game);
		draw_one_vert_ceil_line(i, wall_len, min_dist, game, &c_img);
		i++;
	}



}
