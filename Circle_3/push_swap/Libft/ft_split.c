/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:11:28 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/29 13:18:38 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_sub_s(char const *s, char c)
{
	int	i;
	int	count;

	if (s[0] == '\0')
		return (0);
	if (c == 0 && s[0] != '\0')
		return (1);
	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	return (count + 1);
}

static int	ft_len_sub_s(char const *s, int start, char c)
{
	int	i;

	i = 0;
	while (s[start + i] != c && s[start + i])
		i++;
	return (i);
}

static int	ft_split_start(char **ptr1, char const *s, char c, int count_sub_s)
{
	int	start;
	int	len_sub_s;
	int	i;
	int	j;

	start = 0;
	i = -1;
	while (++i < count_sub_s)
	{
		while ((len_sub_s = ft_len_sub_s(s, start, c)) == 0)
			start += len_sub_s + 1;
		if (!(ptr1[i] = malloc(sizeof(char) * (len_sub_s + 1))))
		{
			while (--i >= 0)
				free(ptr1[i]);
			return (0);
		}
		j = -1;
		while (++j < len_sub_s)
			ptr1[i][j] = s[start + j];
		ptr1[i][j] = '\0';
		start += len_sub_s + 1;
	}
	ptr1[i] = 0;
	return (1);
}

char		**ft_split(char const *s, char c)
{
	char	**ptr1;
	int		count_sub_s;

	if (s == 0)
		return (0);
	count_sub_s = ft_count_sub_s(s, c);
	ptr1 = malloc(sizeof(char *) * (count_sub_s + 1));
	if (!ptr1)
		return (0);
	if (!(ft_split_start(ptr1, s, c, count_sub_s)))
	{
		free(ptr1);
		return (0);
	}
	return (ptr1);
}
