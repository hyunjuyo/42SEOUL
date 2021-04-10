/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:57:42 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/10 13:08:39 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "mlx.h"
# define _USE_MATH_DEFINES
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"

# define MAPX_MAX	1000
# define MAPY_MAX	1000
# define SPR_TYPE	3
# define SPR_MAX_IN_FOV	100
# define CUBE_SIZE	5
# define MINIMAP_RAY_NUM	50

# define MOVE_SPEED	0.52
# define ROT_SPEED_RAD	0.09
# define FOV	60

# define WHITE	0xFFFFFF
# define BLACK	0x000000
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define YELLOW	0xFFFF00
# define CYAN	0x00FFFF
# define MAGENTA	0xFF00FF

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_EXIT			17
# define KEY_A		0
# define KEY_D		2
# define KEY_S		1
# define KEY_W		13
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_SHIFT	257
# define KEY_SPACE	49
# define KEY_ESC	53
# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3

# define EPSILON	0.000001
# define PATH_LEN	50

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct		s_parsing
{
	int				rw;
	int				rh;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				s;
	int				s2;
	int				s3;
	int				c;
	int				f;
}					t_parsing;

typedef struct		s_conf
{
	int				display_w;
	int				display_h;
	int				win_w;
	int				win_h;
	int				map_x;
	int				map_y;
	char			wall_no[PATH_LEN];
	char			wall_so[PATH_LEN];
	char			wall_we[PATH_LEN];
	char			wall_ea[PATH_LEN];
	char			sprite[SPR_TYPE][PATH_LEN];
	int				ceil;
	int				floor;
	int				parsing_complete;
	int				chk_complete;
	int				map_lines;
	t_parsing		check;
	char			**temp_map_addr;
}					t_conf;

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				width;
	int				height;
	int				bpp;
	int				size_l;
	int				endian;
	double			invisible_c;
}					t_img;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_pla
{
	double			x;
	double			y;
	double			th;
	double			ray_th;
	double			view_h;
	int				walk;
	int				jump;
	double			jh_w;
	int				item[2];
	int				get_map;
	t_img			ani;
}					t_pla;

typedef enum		e_dir
{
	EAST,
	WEST,
	SOUTH,
	NORTH
}					t_dir;

typedef struct		s_wall
{
	double			x;
	double			y;
	double			dist;
	t_dir			dir;
}					t_wall;

typedef struct		s_sprite
{
	void			*img;
	int				*data;
	int				width;
	int				height;
	int				bpp;
	int				size_l;
	int				endian;
	double			x;
	double			y;
	double			th;
	double			dist;
	int				length;
}					t_sprite;

typedef struct		s_game
{
	void			*mlx;
	void			*win;
	t_img			img1;
	t_img			c_img;
	t_img			f_img;
	t_pla			player;
	t_wall			*wall;
	t_sprite		spr[SPR_MAX_IN_FOV];
	t_conf			conf;
	int				map_check;
	char			map[MAPX_MAX][MAPY_MAX];
	int				cubsize;
	char			*spr_in_fov;
	char			*save_flag;
	int				pid;
	int				pid_status;
}					t_game;

typedef enum		e_line
{
	VERT,
	HORZ
}					t_line;

typedef struct		s_chk_pnt
{
	double			px;
	double			py;
	double			nx;
	double			ny;
	double			f_nx;
	double			g_ny;
	t_line			line;
	int				mapx;
	int				mapy;
	int				xstep;
	int				ystep;
	t_bool			hit_wall;

}					t_chk_pnt;

typedef struct		s_ray
{
	int				rx;
	int				ry;
	int				xstep;
	int				ystep;
	int				w;
	int				h;
}					t_ray;

typedef struct		s_space
{
	int				vh;
	int				ceil;
	int				floor;
	int				line_len;
}					t_space;

typedef struct		s_dist
{
	double			ceil;
	double			floor;
}					t_dist;

typedef struct		s_info
{
	int				idx;
	int				h;
	int				line_len;
	double			invisible;
	int				start;
}					t_info;

typedef struct		s_idx
{
	int				x;
	int				y;
}					t_idx;

typedef struct		s_bmp
{
	int				fd;
	int				pad;
	int				file_size;
	unsigned char	file_hd[14];
	unsigned char	info_hd[40];
	unsigned char	*img;
}					t_bmp;

int					key_set(int keycode, t_game *game);
int					key_set2(int keycode, t_game *game);
int					draw_minimap(t_game *game);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
int					atoi_n_check(const char *str, char *type);
double				cast_single_ray(int x, t_game *game, int n);
double				get_dist(double x1, double y1, double x2, double y2);
double				deg_to_rad(double th, int type);
double				rad_to_deg(double th);
void				check_steps(double th, int *xstep, int *ystep);
void				draw_fov_rays_on_minimap(t_game *game);
int					draw_player_fov(t_game *game);
int					get_texture_pixel_color(t_info *info, t_game *game,
		t_img *w_img);
void				map_parsing(char *map_file, t_game *game);
void				overlap_check(t_game *game, char *type);
void				save_map_info(char *line, t_game *game);
void				check_conf_type_1(char *line, t_game *game, char *l_ptr,
		char *w_ptr);
void				check_conf_type_6(char *line, t_game *game, char *w_ptr);
void				save_conf_resolution(t_game *game, char **l_ptr,
		char *w_ptr, char type);
int					get_rgb_color(char **l_ptr, char *w_ptr);
void				check_rgb_range(int num);
void				img_file_open_check(t_game *game);
char				*get_next_word(char **l_ptr);
void				check_sprite_in_fov(t_game *game, t_chk_pnt *check);
void				ready_to_draw_sprite(t_game *game);
int					get_vert_line_length(double wdist, t_game *game);
char				*get_spr_path(t_game *game, char spr_type);
void				draw_vert_spr_line(t_game *game, int idx, int j,
		int start_spot);
int					fade_color(int color, double dist, t_game *game,
		double weight);
void				save_player_info(t_game *game, int i, int j, char c);
int					hit_wall_check(t_game *game, int type);
void				map_parsing_wall_check(t_game *game);
void				screen_size_check(t_game *game);
void				texture_floor(t_game *game);
int					check_color_area(int color, int refer_color, int area);
void				check_saving_bmp_file(t_game *game);
void				player_walking(t_game *game);
void				player_jumping_check(t_game *game);
void				get_sky_image_data(t_game *game);
int					get_sky_color(t_game *game, int h, int w);
void				check_player_item_info(t_game *game);
void				draw_gem_info(t_game *game, int info);
void				draw_gem_info_last(t_game *game, t_img *gem);
void				print_parsing_error(char *type, char *message);
int					exit_game(t_game *game);

#endif
