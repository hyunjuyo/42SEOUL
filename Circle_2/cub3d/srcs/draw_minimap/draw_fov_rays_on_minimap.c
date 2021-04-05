/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov_rays_on_minimap.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:11:04 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/05 13:49:57 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_using_xstep(int i, t_idx *idx, t_game *game, t_ray *ray)
{
	ray->rx = idx->x + ray->xstep;
	while (ray->xstep == 1 && ray->rx < (int)(game->wall[i].x * game->cubsize))
	{
		ray->ry = tan(game->player.ray_th) * (ray->rx - idx->x) + idx->y;
		game->img1.data[(ray->h - 1 - ray->ry) * ray->w + ray->rx] = 0x207030;
		ray->rx += ray->xstep;
	}
	while (ray->xstep == -1 && ray->rx > (int)(game->wall[i].x * game->cubsize))
	{
		ray->ry = tan(game->player.ray_th) * (ray->rx - idx->x) + idx->y;
		game->img1.data[(ray->h - 1 - ray->ry) * ray->w + ray->rx] = 0x207030;
		ray->rx += ray->xstep;
	}
}

void	draw_using_ystep(int i, t_idx *idx, t_game *game, t_ray *ray)
{
	ray->ry = idx->y + ray->ystep;
	while (ray->ystep == 1 && ray->ry < (int)(game->wall[i].y * game->cubsize))
	{
		ray->rx = 1 / tan(game->player.ray_th) * (ray->ry - idx->y) + idx->x;
		game->img1.data[(ray->h - 1 - ray->ry) * ray->w + ray->rx] = 0x207030;
		ray->ry += ray->ystep;
	}
	while (ray->ystep == -1 && ray->ry > (int)(game->wall[i].y * game->cubsize))
	{
		ray->rx = 1 / tan(game->player.ray_th) * (ray->ry - idx->y) + idx->x;
		game->img1.data[(ray->h - 1 - ray->ry) * ray->w + ray->rx] = 0x207030;
		ray->ry += ray->ystep;
	}
}

void	draw_one_ray(int i, t_idx *idx, t_game *game)
{
	t_ray	ray;
	double	tan_th;

	tan_th = tan(game->player.ray_th);
	ray.w = game->conf.win_w;
	ray.h = game->conf.map_y * game->cubsize;
	check_steps(game->player.ray_th, &ray.xstep, &ray.ystep);
	if (tan_th <= 1.05 && tan_th >= -1.05)
		draw_using_xstep(i, idx, game, &ray);
	if (1.0 / tan_th <= 1.05 && 1.0 / tan_th >= -1.05)
		draw_using_ystep(i, idx, game, &ray);
}

void	draw_fov_rays_on_minimap(t_game *game)
{
	int		i;
	t_idx	idx;
	int		total_w;
	int		ray_num;

	total_w = game->conf.win_w;
	idx.x = (int)(game->player.x * game->cubsize);
	idx.y = (int)(game->player.y * game->cubsize);
	game->img1.data[(game->conf.map_y * game->cubsize - 1 - idx.y) *
		total_w + idx.x] = BLUE;
	i = 0;
	ray_num = MINIMAP_RAY_NUM;
	game->wall = (t_wall *)ft_calloc(ray_num, sizeof(t_wall));
	while (i < ray_num)
	{
		cast_single_ray(i, game, ray_num);
		draw_one_ray(i, &idx, game);
		i++;
	}
	free(game->wall);
}
