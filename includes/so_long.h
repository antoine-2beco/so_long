/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:01:15 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/19 18:35:13 by ade-beco         ###   ########.fr       */
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
}				t_game;

int	error(char *str);

// init_map.c
int	init_map(t_game *game, t_map *map, char *map_file);

// init_game.c
int	init_mlx(t_game *game);

// map_compliant.c 
int	valid_map_content(t_map *map);
int	rectangular_map(t_map *map);
int	walls_surround(t_map *map);
int	specials_components(t_game *game);

// check_path.c
int	check_path(t_game *game);

#endif