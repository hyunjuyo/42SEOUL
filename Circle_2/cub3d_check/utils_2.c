/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:30:27 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/13 18:21:31 by hyunjuyo         ###   ########.fr       */
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
