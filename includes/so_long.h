/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:01:15 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/12 15:23:03 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
//# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

# include "../libft/libft.h"

typedef struct s_game
{
	t_list		*map;
	int			map_lenght;
	int			map_height;
	int			collectibles;

	int			x_spawn;
	int			y_spawn;
	int			x_exit;
	int			y_exit;
}	t_game;

int	error(char *str);

// check_map.c
int	init_map(t_game **game, t_list **map, char *map_file);

// map_compliant.c 
int	valid_map_content(t_list **map);
int	rectangular_map(t_list **map);
int	walls_surround(t_list **map, int map_lenght);
int	specials_components(t_game **game);


#endif