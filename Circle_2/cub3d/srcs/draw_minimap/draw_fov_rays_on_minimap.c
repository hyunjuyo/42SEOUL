/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov_rays_on_minimap.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:11:04 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/28 18:49:09 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_using_xstep(int i, int px, int py, t_game *game, t_ray *ray)
{
	ray->rx = px + ray->xstep;
	while (ray->xstep == 1 && ray->rx < (int)(game->wall[i].x * CUBE_SIZE))
	{
		ray->ry = tan(game->player.ray_th) * (ray->rx - px) + py;
		game->img2.data[(ray->h - 1 - ray->ry) * ray->w + ray->rx] = GREEN;
		ray->rx += ray->xstep;
	}
	while (ray->xstep == -1 && ray->rx > (int)(game->wall[i].x * CUBE_SIZE))
	{
		ray->ry = tan(game->player.ray_th) * (ray->rx - px) + py;
		game->img2.data[(ray->h - 1 - ray->ry) * ray->w + ray->rx] = GREEN;
		ray->rx += ray->xstep;
	}
}

void	draw_using_ystep(int i, int px, int py, t_game *game, t_ray *ray)
{
	ray->ry = py + ray->ystep;
	while (ray->ystep == 1 && ray->ry < (int)(game->wall[i].y * CUBE_SIZE))
	{
		ray->rx = 1 / tan(game->player.ray_th) * (ray->ry - py) + px;
		game->img2.data[(ray->h - 1 - ray->ry) * ray->w + ray->rx] = GREEN;
		ray->ry += ray->ystep;
	}
	while (ray->ystep == -1 && ray->ry > (int)(game->wall[i].y * CUBE_SIZE))
	{
		ray->rx = 1 / tan(game->player.ray_th) * (ray->ry - py) + px;
		game->img2.data[(ray->h - 1 - ray->ry) * ray->w + ray->rx] = GREEN;
		ray->ry += ray->ystep;
	}
}

void	draw_one_ray(int i, int px, int py, t_game *game)
{
	t_ray	ray;
	double	tan_th;

	tan_th = tan(game->player.ray_th);
	ray.w = game->conf.map_x * CUBE_SIZE;
	ray.h = game->conf.map_y * CUBE_SIZE;
	check_steps(game->player.ray_th, &ray.xstep, &ray.ystep);
	if (tan_th <= 1.0 && tan_th >= -1.0)
		draw_using_xstep(i, px, py, game, &ray);
	if (1.0 / tan_th <= 1.0 && 1.0 / tan_th >= -1.0)
		draw_using_ystep(i, px, py, game, &ray);
}

void	draw_fov_rays_on_minimap(t_game *game)
{
	int		i;
	int		px;
	int		py;
	int		total_w;
	int		ray_num;

	total_w = game->conf.map_x * CUBE_SIZE;
	px = (int)(game->player.x * CUBE_SIZE);
	py = (int)(game->player.y * CUBE_SIZE);
//	game->spr_in_fov = (char *)ft_calloc(game->conf.map_x * game->conf.map_y, sizeof(char));
	game->img2.data[(game->conf.map_y * CUBE_SIZE - 1 - py) * total_w + px] = BLUE;
	i = 0;
	ray_num = MINIMAP_RAY_NUM;
	game->wall = (t_wall *)ft_calloc(ray_num, sizeof(t_wall));
	while (i < ray_num)
	{
		cast_single_ray(i, game, ray_num);
//		draw_one_ray(i, px, py, game);
		i++;
	}
	free(game->wall);
//	free(game->spr_in_fov);
}
