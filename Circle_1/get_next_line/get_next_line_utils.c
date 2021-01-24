/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:01:13 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/01/09 20:10:21 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (0);
	if (!s1[0] && !s2[0])
		return (ft_strdup(""));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(ptr = malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (0);
	i = -1;
	while (++i < len_s1)
		ptr[i] = s1[i];
	while (i < len_s1 + len_s2)
	{
		ptr[i] = s2[i - len_s1];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
