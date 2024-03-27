/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:01:13 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/27 12:16:24 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_imgs(t_game *game)
{
	if (game->wall.alloc)
		mlx_destroy_image(game->mlx, game->wall.xpm);
	if (game->floor.alloc)
		mlx_destroy_image(game->mlx, game->floor.xpm);
	if (game->collectibles.alloc)
		mlx_destroy_image(game->mlx, game->collectibles.xpm);
	if (game->exit_open.alloc)
		mlx_destroy_image(game->mlx, game->exit_open.xpm);
	if (game->exit_closed.alloc)
		mlx_destroy_image(game->mlx, game->exit_closed.xpm);
	if (game->player.alloc)
		mlx_destroy_image(game->mlx, game->player.xpm);
}

static void	free_memory(t_game *game)
{
	size_t	i;

	i = 0;
	if (game && game->sprites_alloc)
		free_imgs(game);
	if (game && game->win_alloc)
		mlx_destroy_window(game->mlx, game->win);
	if (game && game->mlx_alloc)
		free(game->mlx);
	if (game && game->map_alloc)
	{
		while (i < game->map.rows)
			free(game->map.content[i++]);
		free (game->map.content);
	}
	if (game)
		free(game);
}

void	error(char *str, t_game *game)
{
	free_memory(game);
	ft_printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

int	quit(t_game *game, int win)
{
	free_memory(game);
	if (!win)
		ft_printf("Well done, you won !\n");
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2 || (argc == 2 && ft_strchr(argv[1], ' ')))
		error("Bad argument(s)", NULL);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error("Game struct malloc failed", NULL);
	game->map_alloc = 0;
	game->mlx_alloc = 0;
	game->win_alloc = 0;
	game->sprites_alloc = 0;
	init_map(game, argv[1]);
	init_mlx(game);
	mlx_hook(game->win, 2, 0, key_input, game);
	mlx_hook(game->win, 17, 2, quit, game);
	mlx_loop(game->mlx);
	return (1);
}
