/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:01:15 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/21 15:35:38 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

# include "../libft/libft.h"

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_img
{
	void		*xpm;
	int			x;
	int			y;
}				t_img;


typedef struct s_map
{
	char		**content;
	int			rows;
	int			collumns;
	int			collectibles;
	t_pos		spawn;
	t_pos		exit;
}				t_map;

typedef struct s_game
{
	t_map		*map;
	void		*mlx;
	void		*win;

	t_img		wall;
	t_img		floor;
	t_img		collectibles;
	t_img		exit_closed;
	t_img		exit_open;
	t_img		player_up;
	t_img		player_down;
	t_img		player_left;
	t_img		player_right;
}				t_game;

int	error(char *str, t_game *game);

// init_map.c
int	init_map(t_game *game, t_map *map, char *map_file);

// init_game.c
int	init_mlx(t_game *game);

// map_compliant.c 
int	valid_map_content(t_game *game, t_map *map);
int	rectangular_map(t_game *game, t_map *map);
int	walls_surround(t_game *game, t_map *map);
int	specials_components(t_game *game);

// check_path.c
int	check_path(t_game *game);

#endif