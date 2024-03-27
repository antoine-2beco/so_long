/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:33:13 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/27 10:37:56 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map.content[new_y][new_x] == FLOOR
		|| game->map.content[new_y][new_x] == COLLECTIBLE)
	{
		if (game->map.content[new_y][new_x] == COLLECTIBLE)
			game->map.collectibles--;
		game->map.content[game->map.player.y][game->map.player.x] = FLOOR;
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->map.content[new_y][new_x] = PLAYER;
		game->movements++;
		ft_printf("Movements : %i\n", game->movements);
	}
	else if (game->map.content[new_y][new_x] == EXIT \
		&& !game->map.collectibles)
	{
		game->movements++;
		ft_printf("Movements : %i\n", game->movements);
		quit(game, 0);
	}
	map_to_mlx(game);
}

int	key_input(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_UP)
		move_player(game, game->map.player.x, game->map.player.y - 1);
	if (key == KEY_A || key == KEY_LEFT)
		move_player(game, game->map.player.x - 1, game->map.player.y);
	if (key == KEY_D || key == KEY_RIGHT)
		move_player(game, game->map.player.x + 1, game->map.player.y);
	if (key == KEY_S || key == KEY_DOWN)
		move_player(game, game->map.player.x, game->map.player.y + 1);
	if (key == KEY_Q || key == KEY_ESC)
		quit(game, 1);
	return (1);
}
