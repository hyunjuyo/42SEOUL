/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_config2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:03:03 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/05 17:32:14 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_conf_type_6(char *line, t_game *game, char *w_ptr)
{
	if (w_ptr[0] == '1')
	{
		free(w_ptr);
		save_map_info(line, game);
	}
	else
	{
		free(w_ptr);
		printf("Error\nParsing failed : incorrect information\n");
		exit(1);
	}
}
