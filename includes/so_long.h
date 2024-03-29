/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:01:15 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/27 11:52:23 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>

# include "../libft/libft.h"

# define WALL				'1'
# define FLOOR 				'0'
# define COLLECTIBLE  		'C'
# define PLAYER				'P'
# define EXIT 		 		'E'

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2

# define KEY_UP  			126
# define KEY_LEFT  			123
# define KEY_RIGHT 			124
# define KEY_DOWN  			125

# define KEY_Q				12
# define KEY_ESC  			53

# define SP_BUSH			"sprites/bush.xpm"
# define SP_GRASS			"sprites/grass.xpm"
# define SP_COLLECTIBLE		"sprites/collectible.xpm"
# define SP_DOOR_OPEN		"sprites/door_open.xpm"
# define SP_DOOR_CLOSE		"sprites/door_close.xpm"
# define SP_PLAYER			"sprites/player.xpm"

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_img
{
	void		*xpm;
	int			alloc;
	int			x;
	int			y;
}				t_img;

typedef struct s_map
{
	char		**content;
	size_t		rows;
	size_t		collumns;
	size_t		collectibles;
	size_t		exit;
	t_pos		player;
	t_pos		last_player;
}				t_map;

typedef struct s_game
{
	t_map		map;
	void		*mlx;
	void		*win;

	t_img		wall;
	t_img		floor;
	t_img		collectibles;
	t_img		exit_closed;
	t_img		exit_open;
	t_img		player;

	int			map_alloc;
	int			mlx_alloc;
	int			win_alloc;
	int			sprites_alloc;
	size_t		movements;
}				t_game;

void	error(char *str, t_game *game);
int		quit(t_game *game, int win);

// init_map.c
void	init_map(t_game *game, char *map_file);

// init_game.c
void	init_mlx(t_game *game);
int		map_to_mlx(t_game *game);

// map_compliant.c 
void	valid_map_content(t_game *game);
void	rectangular_map(t_game *game);
void	walls_surround(t_game *game);
void	specials_components(t_game *game);

// check_path.c
void	check_path(t_game *game);

//key_input.c
int		key_input(int key, t_game *game);

#endif