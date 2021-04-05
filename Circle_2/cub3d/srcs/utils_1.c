/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:09:22 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/05 13:28:35 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_dist(double x1, double y1, double x2, double y2)
{
	double x_dist;
	double y_dist;

	x_dist = x2 - x1;
	y_dist = y2 - y1;
	return (sqrt(x_dist * x_dist + y_dist * y_dist));
}

double	rad_to_deg(double th)
{
	return (th * 180.0 / M_PI);
}

double	deg_to_rad(double th, int type)
{
	double	rad;

	if (type == 0)
		rad = th * M_PI / 180.0;
	else
	{
		rad = th * M_PI / 180.0;
		if (rad < 0.000001
				|| rad - M_PI * 1 / 2 < 0.000001
				|| rad - M_PI < 0.000001
				|| rad - M_PI * 3 / 2 < 0.000001)
			rad += 0.000002;
	}
	return (rad);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dst);
}
