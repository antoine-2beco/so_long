/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:32:19 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/25 17:57:17 by ade-beco         ###   ########.fr       */
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
	game->exit_open = new_sprite(game, "sprites/door_open.xpm");
	game->exit_closed = new_sprite(game, "sprites/door_close.xpm");
	game->player_up = new_sprite(game, "sprites/player.xpm");
}

static void	find_sprite(t_game *game, int x, int y)
{
	char	component;

	component = game->map.content[y][x];
	if (component == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->wall.xpm,
			x * game->wall.x, y * game->wall.y);
	else if (component == FLOOR)
		mlx_put_image_to_window(game->mlx, game->win, game->floor.xpm,
			x * game->floor.x, y * game->floor.y);
	else if (component == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win, game->collectibles.xpm,
			x * game->collectibles.x, y * game->collectibles.y);
	else if (component == EXIT)
	{
		if (!game->map.collectibles)
			mlx_put_image_to_window(game->mlx, game->win, game->exit_open.xpm,
				x * game->exit_open.x, y * game->exit_open.y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->exit_closed.xpm,
				x * game->exit_closed.x, y * game->exit_closed.y);
	}
	else if (component == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->player_up.xpm,
			x * game->player_up.x, y * game->player_up.y);
}

int	map_to_mlx(t_game *game)
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
	return (1);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error("mlx_init failed", game);
	game->win = mlx_new_window(game->mlx, \
		game->map.collumns * 50, game->map.rows * 50, "so_long");
	if (!game->win)
	{
		free(game->mlx);
		error("mlx_new_window failed", game);
	}
	init_sprites(game);
	map_to_mlx(game);
}
