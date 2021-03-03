/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:09:22 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/03 18:00:23 by hyunjuyo         ###   ########.fr       */
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

double	deg_to_rad(double th)
{
	return (th * M_PI / 180.0);
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
