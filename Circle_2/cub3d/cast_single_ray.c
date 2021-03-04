/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_single_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:25:33 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/04 20:47:29 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_steps(double th, int *xstep, int *ystep)
{
	if (cos(th) > EPSILON)
		*xstep = 1;
	else if (cos(th) < -EPSILON)
		*xstep = -1;
	else
		*xstep = 0;
	if (sin(th) > EPSILON)
		*ystep = 1;
	else if (sin(th) < -EPSILON)
		*ystep = -1;
	else
		*ystep = 0;
}

void	get_next_point(double ray_th, double *px, double *py, t_chk_pnt *check)
{
	if (check->xstep  == 1)
		check.nx = floor(*px) + 1;
	else if (check.xstep == -1)
		check.nx = ceil(*px) - 1;
	else
		check.nx = *px;
	check.f_nx = tan(ray_th) * (check.nx - *px) + *py;
	if (check->ystep == 1)
		check.ny = floor(*py) + 1;
	else if (check.ystep == -1)
		check.ny = ceil(*py) - 1;
	else
		check.ny = *py;
	check.g_ny = 1.0 / tan(ray_th) * (check.ny - *py) + *px;
	if (get_dist(*px, *py, check.nx, check.f_nx)
			< get_dist(*px, *py, check.g_ny, check.ny))
	{
		*px = check.nx;
		*py = check.f_nx;
	}
	else
	{
		*px = check.g_ny;
		*py = check.ny;
	}
}


void	get_wall_point(double ray_th, t_game *game, t_wall *wall)
{
	double		px;
	double		py;
	t_chk_pnt	check;

	px = game->player.x;
	py = game->player.y;
	check_steps(ray_th, &check.xstep, &check.ystep);

	get_next_point(ray_th, &px, &py, &check);
	if (check.xstep == 1)




}

double	cast_single_ray(int i, t_game *game)
{
	double	dist;
	double	ray_th;
	t_wall	wall;

	ray_th = (game->player.th + g_fovh / 2) - (g_fovh / (WIN_W - 1)) * i;
	get_wall_point(ray_th, game, &wall);
	dist = get_dist(game->player.x, game->player.y, wall.x, wall.y);
	return (dist);
}
