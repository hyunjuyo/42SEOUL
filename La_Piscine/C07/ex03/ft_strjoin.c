/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:22:43 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/09 19:34:17 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_sep_len(char *sep)
{
	int i;

	i = 0;
	while (sep[i] != '\0')
		i++;
	return (i);
}

int		ft_strs_len(char **strs, int size)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			j++;
		count += j;
		i++;
	}
	return (count);
}

void	strjoin_start(char *arr, int size, char **strs, char *sep)
{
	int i;
	int strs_num;
	int i_strs;
	int i_sep;

	i = 0;
	strs_num = 0;
	while (strs_num < size)
	{
		i_strs = -1;
		while (strs[strs_num][++i_strs] != '\0')
			arr[i++] = strs[strs_num][i_strs];
		if (strs_num < size - 1)
		{
			i_sep = -1;
			while (sep[++i_sep] != '\0')
				arr[i++] = sep[i_sep];
		}
		strs_num++;
	}
	arr[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		sep_len;
	int		strs_len;

	sep_len = ft_sep_len(sep);
	strs_len = ft_strs_len(strs, size);
	if (size == 0)
		return ((char *)malloc(strs_len + (size - 1) * sep_len + 1));
	arr = (char *)malloc(strs_len + (size - 1) * sep_len + 1);
	if (arr == '\0')
		return (0);
	strjoin_start(arr, size, strs, sep);
	return (arr);
}
