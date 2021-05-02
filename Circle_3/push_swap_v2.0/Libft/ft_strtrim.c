/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 19:39:38 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/30 16:19:11 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start;
	int		len_s1;
	int		i;

	if (!s1 || !set)
		return (0);
	len_s1 = ft_strlen(s1);
	start = 0;
	while (s1[start] && is_set(s1[start], set))
		start++;
	while (len_s1 > 0 && is_set(s1[len_s1 - 1], set))
		len_s1--;
	if (len_s1 - start < 1)
		return (ft_strdup(""));
	ptr = malloc(sizeof(char) * ((len_s1 - start) + 1));
	if (!ptr)
		return (0);
	i = -1;
	while (++i < len_s1 - start)
		ptr[i] = s1[start + i];
	if (len_s1 - start > 0)
		ptr[i] = '\0';
	return (ptr);
}
