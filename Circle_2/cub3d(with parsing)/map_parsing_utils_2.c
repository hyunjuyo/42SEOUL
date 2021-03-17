/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:17:49 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/17 12:29:52 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_next_word(char **l_ptr)
{
	char	*w_ptr;
	int		i;

	i = 0;
	while ((*l_ptr)[i] != ' ' && (*l_ptr)[i] != '\0')
		i++;
	if ((*l_ptr)[i] == '\0')
	{
		w_ptr = ft_strdup(*l_ptr);
        *l_ptr += i + 1;
		return (w_ptr);
	}
	(*l_ptr)[i] = '\0';
	w_ptr = ft_strdup(*l_ptr);
	*l_ptr += i + 1;
	i = 0;
	while ((*l_ptr)[i] == ' ')
		i++;
	*l_ptr += i;
	return (w_ptr);
}

char	*join_next_words(char *l_ptr, char *w_ptr, int max_count)
{
	int		i;
	char	*temp1;
	char	*temp2;

	i = 0;
	while (i < max_count)
	{
		temp1 = w_ptr;
		temp2 = get_next_word(&l_ptr);
		w_ptr = ft_strjoin(temp1, temp2);
		free(temp1);
		free(temp2);
		i++;
	}
	return (w_ptr);
}

int		get_rgb_color(char *l_ptr, char *w_ptr)
{
	int		rgb;
	char	**color_info;
	int		num;
	int		i;

	w_ptr = join_next_words(l_ptr, w_ptr, 4);
	rgb = 0x0;
	color_info = ft_split(w_ptr, ',');
	i = 0;
	while (i < 3)
	{
		rgb *= 0x10 * 0x10;
		if (!color_info[i])
			return (-1);
		if (i == 2 && ft_strlen(color_info[i]) > 3)
				color_info[i][3] = '\0';
		num = ft_atoi(color_info[i]);
		if (num < 0 || num > 255)
		{
			printf("parsing failed : incorrect RGB color(num : %d)\n", num);
			printf("Error\n");
			exit(1);
		}
		rgb += num;
		printf("color_info[i] : %s\n", color_info[i]);
		printf("wow!! %d %#X\n", rgb, rgb);
		i++;
	}
	return (rgb);
}
