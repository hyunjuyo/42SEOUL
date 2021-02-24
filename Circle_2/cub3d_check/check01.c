/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 12:00:29 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/02/21 17:52:29 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define WIN_WIDTH	1000
#define WIN_HEIGHT	1000

#define IMG_WIDTH	300
#define IMG_HEIGHT	300

#define KEY_A	0
#define KEY_D	2
#define KEY_S	1
#define KEY_W	13
#define KEY_ESC	53

typedef struct	s_img
{
	void	*img_ptr1;
	void	*img_ptr2;
	int		*data_ptr;
	int		bpp;
	int		size_l;
	int		endian;
}				t_img;

typedef struct	s_param
{
	int		x;
	int		y;
}				t_param;

void	param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
}

int		key_01(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->y++;
	else if (keycode == KEY_S)
		param->y--;
	else if (keycode == KEY_A)
		param->x--;
	else if (keycode == KEY_D)
		param->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("(x, y) => (%d, %d)\n", param->x, param->y);
	return (0);
}

void	new_image_modify(void *mlx_ptr, t_img *img)
{
	int	cnt_w;
	int	cnt_h;

	img->img_ptr2 = mlx_new_image(mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img->data_ptr = (int *)mlx_get_data_addr(img->img_ptr2, &img->bpp, &img->size_l, &img->endian);

	cnt_h = -1;
	while (++cnt_h < IMG_HEIGHT)
	{
		cnt_w = -1;
		while (++cnt_w < IMG_WIDTH)
		{
			if (cnt_w % 3 == 2)
				img->data_ptr[cnt_h * IMG_WIDTH + cnt_w] = 0x0000FF;
			else
				img->data_ptr[cnt_h * IMG_WIDTH + cnt_w] = 0xFFFFFF;
		}
	}
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_param	param;
	t_img	img;
	int		img_width;
	int		img_height;

	param_init(&param);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "check01");
	img.img_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "images/wall_e.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr1, 300, 300);
	new_image_modify(mlx_ptr, &img);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr2, 0, 0);
	mlx_hook(win_ptr, 2, 0, key_01, &param);
	mlx_loop(mlx_ptr);
}
