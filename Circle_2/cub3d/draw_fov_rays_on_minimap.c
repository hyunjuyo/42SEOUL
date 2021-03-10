/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov_rays_on_minimap.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:11:04 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/10 12:45:53 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_using_xstep(int px, int py, t_game *game, t_wall *wall, t_ray *ray)
{
	ray->rx = px + ray->xstep;
	while (ray->xstep == 1 && ray->rx < (int)(wall->x * CUBE_SIZE))
	{
		ray->ry = tan(game->player.ray_th) * (ray->rx - px) + py;
		game->img2.data[(ray->h - 1 - ray->ry) * ray->w + ray->rx] = GREEN;
		ray->rx += ray->xstep;
	}
	while (ray->xstep == -1 && ray->rx > (int)(wall->x * CUBE_SIZE))
	{
		ray->ry = tan(game->player.ray_th) * (ray->rx - px) + py;
		game->img2.data[(ray->h - 1 - ray->ry) * ray->w + ray->rx] = GREEN;
		ray->rx += ray->xstep;
	}
}

void	draw_using_ystep(int px, int py, t_game *game, t_wall *wall, t_ray *ray)
{
	ray->ry = py + ray->ystep;
	while (ray->ystep == 1 && ray->ry < (int)(wall->y * CUBE_SIZE))
	{
		ray->rx = 1 / tan(game->player.ray_th) * (ray->ry - py) + px;
		game->img2.data[(ray->h - 1 - ray->ry) * ray->w + ray->rx] = GREEN;
		ray->ry += ray->ystep;
	}
	while (ray->ystep == -1 && ray->ry > (int)(wall->y * CUBE_SIZE))
	{
		ray->rx = 1 / tan(game->player.ray_th) * (ray->ry - py) + px;
		game->img2.data[(ray->h - 1 - ray->ry) * ray->w + ray->rx] = GREEN;
		ray->ry += ray->ystep;
	}
}

void	draw_one_ray(int px, int py, t_game *game, t_wall *wall)
{
	t_ray	ray;
	double	tan_th;

	tan_th = tan(game->player.ray_th);
	ray.w = MAP_X * CUBE_SIZE;
	ray.h = MAP_Y * CUBE_SIZE;
	check_steps(game->player.ray_th, &ray.xstep, &ray.ystep);
	if (tan_th <= 1.0 && tan_th >= -1.0)
		draw_using_xstep(px, py, game, wall, &ray);
	else if (1.0 / tan_th <= 1.0 && 1.0 / tan_th >= -1.0)
		draw_using_ystep(px, py, game, wall, &ray);
}

void	draw_fov_rays_on_minimap(t_game *game, t_wall *wall)
{
	int		i;
	int		px;
	int		py;
	int		total_w;
	int		ray_num;

	total_w = MAP_X * CUBE_SIZE;
	px = (int)(game->player.x * CUBE_SIZE);
	py = (int)(game->player.y * CUBE_SIZE);
	game->img2.data[(MAP_Y * CUBE_SIZE - 1 - py) * total_w + px] = BLUE;
	i = 0;
	ray_num = MINIMAP_RAY_NUM;
	while (i < ray_num)
	{
		cast_single_ray(i, game, wall, ray_num);
		draw_one_ray(px, py, game, wall);
		i++;
	}
}
