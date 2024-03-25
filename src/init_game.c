/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:32:19 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/25 13:32:39 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_img	new_sprite(t_game *game, char *path)
{
	t_img	sprite;

	sprite.xpm = mlx_xpm_file_to_image(game->mlx, path, &sprite.x, &sprite.y);
	if (!sprite.xpm)
		error("mlx_xpm_file_to_image failed", game);
	return (sprite);
}

static void	init_sprites(t_game *game)
{
	game->wall = new_sprite(game, "sprites/bush.xpm");
	game->floor = new_sprite(game, "sprites/grass.xpm");
	game->collectibles = new_sprite(game, "sprites/collectible.xpm");
	game->exit_closed = new_sprite(game, "sprites/door.xpm");
	game->player_up = new_sprite(game, "sprites/player.xpm");
}

static void	find_sprite(t_game *game, int x, int y)
{
	char	component;

	ft_printf("%i, %i\n", x, y);
	ft_printf("%c\n", game->map.content[x][y]);
	component = game->map.content[x][y];
	if (component == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall.xpm,
			x * game->wall.x, y * game->wall.y);
	else if (component == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor.xpm,
			x * game->floor.x, y * game->floor.y);
	else if (component == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectibles.xpm,
			x * game->collectibles.x, y * game->collectibles.y);
	else if (component == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_closed.xpm,
			x * game->exit_closed.x, y * game->exit_closed.y);
	else if (component == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player_up.xpm,
			x * game->player_up.x, y * game->player_up.y);
}

static void	map_to_mlx(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.collumns)
		{
			find_sprite(game, x, y);
			x++;
		}
		y++;
	}
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error("mlx_init failed", game);
	game->win = mlx_new_window(game->mlx,
			game->map.rows * 50, game->map.collumns * 50, "so_long");
	if (!game->win)
	{
		free(game->mlx);
		error("mlx_new_window failed", game);
	}
	init_sprites(game);
	map_to_mlx(game);
	mlx_loop(game->mlx);
}
