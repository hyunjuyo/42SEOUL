/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:12:51 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/21 18:21:20 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>  //test

void    check_error_int1(t_atoi_info *info, unsigned int num)
{
    if (num < info->temp)
    {
        write(1, "Error\n", 6);
        write(3, "Error\n", 6);
        exit(1);
    }
}

void	check_error_int2(t_atoi_info *info, char *str, unsigned int num)
{
	if (info->check == 0 || (int)ft_strlen(str) != info->i)
    {
        write(1, "Error\n", 6);
        write(3, "Error\n", 6);
        exit(1);
    }
    if (info->sign == 1 && num > 2147483647)
    {
        write(1, "Error\n", 6);
        write(3, "Error\n", 6);
        exit(1);
    }
    if (info->sign == -1 && num > 2147483648)
    {
        write(1, "Error\n", 6);
        write(3, "Error\n", 6);
        exit(1);
    }
}

void    check_error_dup(int *stor, int idx, int num)
{
    int i;

    i = 0;
    while (i < idx)
    {
        if (stor[i] == num)
        {
            write(1, "Error\n", 6);
            write(3, "Error\n", 6);
            exit(1);
        }
        i++;
    }
}

int		atoi_error_check(char *str)
{
	t_atoi_info		info;
	unsigned int	num;

    num = 0;
    ft_memset(&info, 0, sizeof(t_atoi_info));
	info.sign = 1;
	while ((str[info.i] >= 9 && str[info.i] <= 13) || str[info.i] == ' ')
		info.i++;
	if (str[info.i] == '+' || str[info.i] == '-')
	{
		if (str[info.i] == '-')
			info.sign *= -1;
		info.i++;
	}
	while (str[info.i] >= '0' && str[info.i] <= '9')
	{
        info.check++;
        info.temp = num;
		num *= 10;
		num += str[info.i] - '0';
        check_error_int1(&info, num);
		info.i++;
	}
	check_error_int2(&info, str, num);
	return (num * info.sign);
}

int		main(int argc, char *argv[])
{
	int	stor[STORAGE_SIZE];
	int	i;
    int num;

	if (argc == 1)
		exit(0);
	ft_memset(stor, 0, sizeof(int) * STORAGE_SIZE);
	i = 0;
	while (i < argc - 1)
	{
        num = atoi_error_check(argv[i + 1]);
        check_error_dup(stor, i, num);
		stor[i] = num;
		i++;
	}
	i = -1;  //test
	while (++i < argc - 1)  //test
		printf("%d ", stor[i]);  //test
	return (0);
}
