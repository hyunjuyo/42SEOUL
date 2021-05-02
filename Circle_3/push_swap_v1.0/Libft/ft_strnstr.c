/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:42:28 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/26 14:39:24 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str_l, const char *str_s, size_t len)
{
	int		i;
	int		count;
	char	*ptr;
	int		len_str_s;

	ptr = 0;
	if (!str_s[0])
		ptr = (char *)str_l;
	len_str_s = ft_strlen(str_s);
	count = 0;
	i = -1;
	while (str_l[++i] && (size_t)(i + len_str_s) <= len)
	{
		if (str_l[i] == str_s[0])
		{
			while (str_l[i + count] == str_s[count] && count < len_str_s)
				count++;
			if (count == len_str_s)
				return (ptr = (char *)str_l + i);
			count = 0;
		}
	}
	return (ptr);
}
