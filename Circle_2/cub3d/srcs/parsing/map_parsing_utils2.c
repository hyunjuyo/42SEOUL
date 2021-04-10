/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:32:53 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/10 11:42:05 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	overlap_check(t_game *game, char *type)
{
	if (ft_strncmp(type, "Rw", 2) == 0 && game->conf.check.rw == 0)
		game->conf.check.rw = 1;
	else if (ft_strncmp(type, "Rh", 2) == 0 && game->conf.check.rh == 0)
		game->conf.check.rh = 1;
	else if (ft_strncmp(type, "NO", 2) == 0 && game->conf.check.no == 0)
		game->conf.check.no = 1;
	else if (ft_strncmp(type, "SO", 2) == 0 && game->conf.check.so == 0)
		game->conf.check.so = 1;
	else if (ft_strncmp(type, "WE", 2) == 0 && game->conf.check.we == 0)
		game->conf.check.we = 1;
	else if (ft_strncmp(type, "EA", 2) == 0 && game->conf.check.ea == 0)
		game->conf.check.ea = 1;
	else if (ft_strncmp(type, "S", 2) == 0 && game->conf.check.s == 0)
		game->conf.check.s = 1;
	else if (ft_strncmp(type, "S2", 2) == 0 && game->conf.check.s2 == 0)
		game->conf.check.s2 = 1;
	else if (ft_strncmp(type, "S3", 2) == 0 && game->conf.check.s3 == 0)
		game->conf.check.s3 = 1;
	else if (ft_strncmp(type, "C", 2) == 0 && game->conf.check.c == 0)
		game->conf.check.c = 1;
	else if (ft_strncmp(type, "F", 2) == 0 && game->conf.check.f == 0)
		game->conf.check.f = 1;
	else
		print_parsing_error(type, "overlap information");
}

void	check_rgb_range(int num)
{
	if (num < 0 || num > 255)
	{
		printf("Error\nParsing failed : RGB colors in range [0,255] \
(num : %d)\n", num);
		exit(1);
	}
}

void	print_parsing_error(char *type, char *message)
{
	printf("Error\nParsing failed : [%s]%s\n", type, message);
	exit(1);
}

void	check_num(int i, const char *str, char *type)
{
	if (i != (int)ft_strlen(str))
	{
		printf("Error\nParsing failed : [%s]incorrect information\n", type);
		exit(1);
	}
}

int		atoi_n_check(const char *str, char *type)
{
	int				i;
	int				sign;
	unsigned long	num;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	check_num(i, str, type);
	return (num * sign);
}
