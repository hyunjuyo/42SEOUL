/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:10:48 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/01/19 17:37:57 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "./Libft/libft.h"

typedef struct	s_flags
{
	int		i;
	int		isminus;
	int		iszero;
	int		width;
	int		prcs;
	int		isast1;
	int		isast2;
	int		iserror;
	int		count;
}				t_flags;

typedef struct	s_opts
{
	int		len_n;
	int		len_max;
	int		minus;
	int		len_prcs;
}				t_opts;

void			check_flags_c(char n, const char *args, t_flags *flags);
void			check_flags_s(char *str, const char *args, t_flags *flags);
void			check_flags_p(void *ptr, const char *args, t_flags *flags);
void			check_flags_di(int n, const char *args, t_flags *flags);
void			check_flags_u(unsigned int n, const char *args, t_flags *flags);
void			check_flags_x(unsigned int n, const char *args, t_flags *flags);
void			check_w_p(const char *args, int *start, t_flags *flags);
void			start_printf_c(unsigned char n, t_flags *flags);
void			start_printf_s(char *str, t_flags *flags);
void			start_printf_p(void *ptr, t_flags *flags);
void			start_printf_di(int n, t_flags *flags);
void			start_printf_u(unsigned int n, t_flags *flags);
void			start_printf_x(unsigned int n, t_flags *flags, char c);
void			*ptr_to_hex(long long ptr);
char			*ft_utoa(unsigned int n);
char			*ft_utoa_hex(unsigned int n);
void			convert_to_hex(long long ptr, char *arr, int *i);
void			toupper_str(char *str);

#endif
