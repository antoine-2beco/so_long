/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:01:13 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/25 10:52:04 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error(char *str, t_game *game)
{
	if (game->map_alloc)
		free(game->map);
	free(game);
	ft_printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_game	*game;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	game = (t_game *)malloc(sizeof(t_game));
	game->map_alloc = 0;
	if (!game || !map)
	{
		error("Struct malloc failed", game);
		free (map);
	}
	if (argc != 2)
	{
		error("Bad argument", game);
		free (map);
	}
	init_map(game, map, argv[1]);
	init_mlx(game);
	return (1);
}
