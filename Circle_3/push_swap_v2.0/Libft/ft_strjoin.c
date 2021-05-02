/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 19:00:12 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/30 16:06:39 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (len_s1 + len_s2 != 0)
		ptr[i] = '\0';
	return (ptr);
}
