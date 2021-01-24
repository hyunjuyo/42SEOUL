/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 03:10:30 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/10 08:21:07 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "struct.h"
# include "read_info.h"

extern	t_map_info	g_map_inf;
extern	int		g_len;

t_spot	*copy_row(t_spot *row);
t_spot	*chk_x(char *ch, t_spot *row, int *idx, int *flag);
int		chk_len(char *ch, int *idx, int j, int *flag);
t_spot	**read_map(int fd, int *flag);

#endif
