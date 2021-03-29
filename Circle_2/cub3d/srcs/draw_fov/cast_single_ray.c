/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_single_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:25:33 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/29 19:51:35 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	check_next_idx(int step_info, double p_idx)
{
	double	n_idx;

	if (step_info == 1)
		n_idx = floor(p_idx) + 1;
	else if (step_info == -1)
		n_idx = ceil(p_idx) - 1;
	else
		n_idx = p_idx;
	return (n_idx);
}

void	get_next_point(double ray_th, double *px, double *py, t_chk_pnt *check)
{
	double	dist_v;
	double	dist_h;

	check->nx = check_next_idx(check->xstep, *px);
	check->f_nx = tan(ray_th) * (check->nx - *px) + *py;
	check->ny = check_next_idx(check->ystep, *py);
	check->g_ny = 1.0 / tan(ray_th) * (check->ny - *py) + *px;
	if ((dist_v = get_dist(*px, *py, check->nx, check->f_nx)) == 0.0)
		dist_v = INFINITY;
	if ((dist_h = get_dist(*px, *py, check->g_ny, check->ny)) == 0.0)
		dist_h = INFINITY;
//	printf("tan(th) : %f, 1 / tan(th) : %f\n", tan(ray_th), 1.0 / tan(ray_th));
//	printf("dist_v : %f(%f, %f), dist_h : %f(%f, %f)\n", dist_v, check->nx, check->f_nx, dist_h, check->g_ny, check->ny);
	if (dist_v < dist_h)
	{
		*px = check->nx;
		*py = check->f_nx;
		check->line = VERT;
	}
	else
	{
		*px = check->g_ny;
		*py = check->ny;
		check->line = HORZ;
	}
}

int		check_dir(int i, t_chk_pnt *check, t_game *game)
{
	int	minus;

	minus = 0;
	if (check->line == VERT)
	{
		if (check->xstep == 1)
			game->wall[i].dir = WEST;
		else
		{
			minus = -1;
			game->wall[i].dir = EAST;
		}
	}
	else
	{
		if (check->ystep == 1)
			game->wall[i].dir = SOUTH;
		else
		{
			minus = -1;
			game->wall[i].dir = NORTH;
		}
	}
	return (minus);
}

void	get_wall_point(int i, double ray_th, t_game *game)
{
	t_chk_pnt	check;

	check.px = game->player.x;
	check.py = game->player.y;
	check_steps(ray_th, &check.xstep, &check.ystep);
	check.hit_wall = FALSE;
	while (!check.hit_wall)
	{
		get_next_point(ray_th, &check.px, &check.py, &check);
		if (check.line == VERT)
		{
			check.mapx = (int)check.px + check_dir(i, &check, game);
			check.mapy = (int)check.py;
		}
		else
		{
			check.mapx = (int)check.px;
			check.mapy = (int)check.py + check_dir(i, &check, game);
		}
		if (game->map[check.mapx][check.mapy] == '1')
			check.hit_wall = TRUE;
		check_sprite_in_fov(game, &check);
	}
	game->wall[i].x = check.px;
	game->wall[i].y = check.py;
}

double	cast_single_ray(int i, t_game *game, int ray_num)
{
	double	dist;
	double	ray_th;
	double	fov_h;

	fov_h = deg_to_rad(FOV, 0);
	ray_th = (game->player.th + fov_h / 2) - (fov_h / (ray_num - 1)) * i;
	game->player.ray_th = ray_th;
	get_wall_point(i, ray_th, game);
//	printf("ray : %d, ray_th : %f, wall : (%f, %f)\n", i, rad_to_deg(ray_th), game->wall[i].x, game->wall[i].y);
	dist =
		get_dist(game->player.x, game->player.y, game->wall[i].x, game->wall[i].y);
	return (dist);
}
