/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:27:12 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/02 14:30:43 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int idx_d;
	int idx_s;

	idx_d = 0;
	while (dest[idx_d] != '\0')
		idx_d++;
	idx_s = 0;
	while (src[idx_s] != '\0')
	{
		dest[idx_d] = src[idx_s];
		idx_d++;
		idx_s++;
	}
	dest[idx_d] = '\0';
	return (dest);
}
