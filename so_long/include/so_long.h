/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:59:59 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/18 16:04:31 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"

# define WALLS "./images/brick-50-50.xpm"
# define DOOR "./images/door.xpm"
# define COINS "./images/crystal_01d.xpm"
# define FLOOR "./images/Dirt_06-50x50-clean.xpm"
# define PLAYER "./images/chevalier.xpm"

# define BLOCK 50

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

typedef struct s_setup
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_setup;

typedef struct s_images
{
	void	*img_0;
	void	*img_1;
	void	*img_P;
	void	*img_E;
	void	*img_C;
}t_images;

typedef struct s_map
{
	int		exit;
	int		pos;
	int		coin;
	size_t	map_height;
	size_t	map_width;
	char	**map;
}t_map;

typedef struct s_vars
{
	void			*mlx;
	void			*window;
	char			**map;
	struct s_images	images;
	struct s_setup	set_up;
	struct s_map	map_vars;
}t_vars;

typedef struct s_pos
{
	int	x;
	int	y;
}t_pos;

int		error_manager(char *msg, int key_error);
t_map	get_map(char *map_name);
int		check_map_paths(char **map, t_map *count);

int	get_pos(char **map, char letter, t_pos *pos);
int	ft_hook_events(int keycode, t_vars *vars);
int close_window(t_vars *vars);

#endif