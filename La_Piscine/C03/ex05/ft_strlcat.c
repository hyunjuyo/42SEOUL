/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:03:11 by hyunjuyo          #+#    #+#             */
/*   Updated: 2020/12/02 14:36:24 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	count;
	unsigned int	src_len;
	unsigned int	result;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	count = 0;
	while (src[count] != '\0' && dest_len + count + 1 < size)
	{
		dest[dest_len + count] = src[count];
		count++;
	}
	dest[dest_len + count] = '\0';
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size >= dest_len)
		result = src_len + dest_len;
	else
		result = src_len + size;
	return (result);
}
