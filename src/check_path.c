/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:16:06 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/27 11:37:41 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	floodfill(t_map *backup_map, int x, int y)
{
	if (backup_map->content[y][x] == WALL)
		return ;
	else if (backup_map->content[y][x] == COLLECTIBLE)
	{
		backup_map->content[y][x] = WALL;
		backup_map->collectibles++;
	}
	else if (backup_map->content[y][x] == EXIT)
	{
		backup_map->content[y][x] = WALL;
		backup_map->exit++;
		return ;
	}
	backup_map->content[y][x] = WALL;
	floodfill(backup_map, x + 1, y);
	floodfill(backup_map, x - 1, y);
	floodfill(backup_map, x, y + 1);
	floodfill(backup_map, x, y - 1);
}

void	check_path(t_game *game)
{
	t_map	*backup_map;
	size_t	i;

	backup_map = malloc(sizeof(t_map));
	if (!backup_map)
		error("malloc in check_path failed", game);
	backup_map->collectibles = 0;
	backup_map->exit = 0;
	backup_map->content = game->map.content;
	floodfill(backup_map, game->map.player.x, game->map.player.y);
	if (backup_map->collectibles != game->map.collectibles
		|| !backup_map->exit)
	{
		free(backup_map);
		error("Every components doesn't have a path", game);
	}
	i = 0;
	while (i < game->map.rows)
		free(backup_map->content[i++]);
	free(backup_map->content);
	free(backup_map);
}
