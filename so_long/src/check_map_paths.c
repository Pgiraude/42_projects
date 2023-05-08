

#include "../include/so_long.h"

typedef struct s_save
{
	int	x;
	int	y;
}t_save;

int	check_map_path(char **map, t_count *count)
{
	size_t	x;
	size_t	y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == 'P')
				break;
		}
	}

	t_save	save;

	save.x = x;
	save.y = y;
}