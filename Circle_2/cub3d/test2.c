#include "cub3d.h"

int	main(void)
{
	double	dist;
	t_game	game;
	t_wall	wall;
	int		i;

	game.player.x = 1.5;
	game.player.y = 1.5;
	game.player.th = 100.0;
	i = 0;
	while (i < WIN_W / 10)
	{
		dist = cast_single_ray(i, &game, &wall);
		printf("%d, ray_th : %f, dist : %f\n", i, game.player.ray_th, dist);
		i++;
	}
	return (0);
}
