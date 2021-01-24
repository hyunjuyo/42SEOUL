/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 03:10:18 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/10 08:32:01 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_INFO_H
# define READ_INFO_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "struct.h"

extern	t_map_info	g_map_inf;

int	ft_atoi(char *nstr);
int	is_validinfo(char *th);
int	read_map_info(int fd, int *flag);

#endif
