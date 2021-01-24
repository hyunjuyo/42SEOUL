/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 03:10:42 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/10 03:10:55 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_spot
{
	char	thing;
	int		score;
}					t_spot;

typedef struct		s_map_info
{
	int		xlen;
	int		ylen;
	char	blank;
	char	full;
	char	obstacle;
}					t_map_info;

typedef struct		s_max_square {

	int		x;
	int		y;
	int		len;

}					t_max_square;

#endif
