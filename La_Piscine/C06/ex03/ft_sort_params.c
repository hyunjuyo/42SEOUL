/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:44:05 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/07 18:59:19 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_compare(char *arr1, char *arr2)
{
	int i;

	i = 0;
	while (arr1[i] != '\0' && arr2[i] != '\0')
	{
		if (arr1[i] != arr2[i])
			return (arr1[i] - arr2[i]);
		i++;
	}
	return (arr1[i] - arr2[i]);
}

void	ft_swap(char *arr1[], char *arr2[])
{
	char *temp;

	temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

void	ft_sort(int argc, char *argv[])
{
	int		start;
	int		count;

	start = 0;
	while (++start < argc)
	{
		count = 1;
		while (start + count < argc)
		{
			if (ft_compare(argv[start], argv[start + count]) > 0)
				ft_swap(&argv[start], &argv[start + count]);
			count++;
		}
	}
}

int		main(int argc, char *argv[])
{
	int		num;
	int		i;

	ft_sort(argc, argv);
	num = 0;
	while (++num < argc)
	{
		i = -1;
		while (argv[num][++i] != '\0')
			write(1, &argv[num][i], 1);
		write(1, "\n", 1);
	}
	return (0);
}
