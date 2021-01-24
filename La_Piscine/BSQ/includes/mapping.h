/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 03:10:00 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/10 03:11:11 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPPING_H
# define MAPPING_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "struct.h"

extern	t_map_info	g_map_inf;

int					cmpnums(int a, int b, int c);
void				maxlen(t_spot **map, int x, int y);
t_max_square		findmaxsquare(t_spot **map);
void				draw_maxsquare(t_spot **map, t_max_square max_sqr);
void				draw_map(t_spot **map);

#endif
