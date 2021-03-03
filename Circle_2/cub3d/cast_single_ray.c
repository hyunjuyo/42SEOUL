/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_single_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:25:33 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/03 18:10:34 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_wall_point(double ray_th, double px, double py, t_wall *w_point)
{




}

double	cast_single_ray(int i, t_game *game)
{
	double	dist;
	double	ray_th;
	t_wall	w_point;

	ray_th = (game->player.th + fov_h / 2) - (fov_h / (WIN_W - 1)) * i;
	get_wall_point(ray_th, game->player.x, game->player.y, &w_point);
	dist = get_dist(game->player.x, game->player.y, w_point.x, w_point.y);
	return (dist);
}
