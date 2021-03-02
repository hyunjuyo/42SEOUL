#include "mlx/mlx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

#define deg2rad(th)	((th)*M_PI/180.0)

#define WIN_W	640
#define WIN_H   360
#define FOV		60
#define FOV_H	deg2rad(FOV)

/* Map Info */
#define M_ROW   7
#define M_COL   7
#define M_TILE_SIZE 10

/* Image Info */
#define MAP_W   M_ROW * M_TILE_SIZE
#define MAP_H   M_COL * M_TILE_SIZE

#define WHITE   0xFFFFFF
#define BLACK   0x000000
#define RED     0xFF0000
#define GREEN   0x00FF00
#define BLUE    0x0000FF
#define YELLOW  0xFFFF00
#define CYAN    0x00FFFF
#define MAGENTA 0xFF00FF

#define X_EVENT_KEY_PRESS   2
#define KEY_A   0
#define KEY_D   2
#define KEY_S   1
#define KEY_W   13
#define KEY_ESC 53

typedef struct  s_img
{
    void    *img;
    int     *data;
    int     bpp;
    int     size_l;
    int     endian;
}               t_img;

typedef struct  s_pla
{
    int     x;
    int     y;
}               t_pla;

typedef struct  s_game
{
    void    *mlx;
    void    *win;
    t_img   img;
    t_pla   player;
    int     map[M_ROW][M_COL];
}               t_game;


int     key_set(int keycode, t_game *game);
int     draw_minimap(t_game *game);
void    *ft_memcpy(void *dst, const void *src, size_t n);