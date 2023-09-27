/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:59:59 by pgiraude          #+#    #+#             */
/*   Updated: 2023/09/19 16:21:14 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"

# define WALLS "./images/walls.xpm"
# define DOOR "./images/exit.xpm"
# define DOORCL "./images/exitclose_chevalier.xpm"
# define COINS "./images/crystal_backgrnd.xpm"
# define FLOOR "./images/background.xpm"
# define PLAYER "./images/chevalier_backgrnd.xpm"

# define BLOCK 50

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

typedef struct s_images
{
	void	*img_0;
	void	*img_1;
	void	*img_p;
	void	*img_e;
	void	*img_c;
	void	*img_x;
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
	int				nbr_moves;
	struct s_images	images;
	struct s_map	map_vars;
}t_vars;

typedef struct s_pos
{
	int	x;
	int	y;
}t_pos;

int		error_manager(char *msg, int key_error);
t_map	check_map_conformity(char *map_name);
int		check_map_paths(char **map, t_map *count);
int		check_all_paths(char **map, t_pos *cur, t_map *count, t_list **path);

int		ft_hook_events(int keycode, t_vars *vars);
int		close_window(t_vars *vars, int status);

int		push_map_to_window(t_vars *vars);
int		initialize_images(t_vars *vars);

int		get_pos(char **map, char letter, t_pos *pos);
int		check_file_extension(char *file_name, char *extension);

#endif