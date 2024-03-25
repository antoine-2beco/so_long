/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:01:13 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/25 18:11:30 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error(char *str, t_game *game)
{
	int	i;

	i = 0;
	if (game && game->map_alloc)
	{
		while (i < game->map.rows)
			free(game->map.content[i++]);
		free (game->map.content);
	}
	if (game)
		free(game);
	ft_printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		error("Bad argument", NULL);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error("Game struct malloc failed", NULL);
	game->map_alloc = 0;
	init_map(game, argv[1]);
	init_mlx(game);
	mlx_hook(game->win, 02, 0, key_input, game);
	//mlx_hook(game->win, 12, 15, map_to_mlx, game);
	mlx_loop(game->mlx);
	return (1);
}
