/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:32:53 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/09 15:35:02 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
