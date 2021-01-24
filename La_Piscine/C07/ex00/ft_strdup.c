/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:38:21 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/08 20:46:48 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	str = (char *)malloc(ft_strlen(src) + 1);
	if (str == '\0')
		return (0);
	i = -1;
	while (src[++i] != '\0')
		str[i] = src[i];
	str[i] = src[i];
	return (str);
}
