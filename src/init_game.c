/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:32:19 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/21 15:40:19 by ade-beco         ###   ########.fr       */
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
	game->collectibles = new_sprite(game, "sprites/collectible.xpm");
	game->exit_closed = new_sprite(game, "sprites/door.xpm");
	game->floor = new_sprite(game, "sprites/grass.xpm");
	game->player_up = new_sprite(game, "sprites/player.xpm");
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error("mlx_init failed", game);
	game->win = mlx_new_window(game->mlx,
			game->map->rows * 50, game->map->collumns * 50, "so_long");
	if (!game->win)
	{
		free(game->mlx);
		error("mlx_new_window failed", game);
	}
	init_sprites(game);
	mlx_loop(game->mlx);
	return (1);
}
