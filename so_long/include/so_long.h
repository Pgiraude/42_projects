/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:59:59 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/08 16:58:51 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}t_vars;

typedef struct s_count
{
	int	exit;
	int	pos;
	int	coin;
	size_t	map_height;
	size_t	map_width;
}t_count;

int	error_manager(char *msg, int key_error);
int get_map(char *map_name);
int	check_map_paths(char **map, t_count *count);

#endif