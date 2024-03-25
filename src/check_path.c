/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:16:06 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/25 15:29:34 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	floodfill(t_map *backup_map, int x, int y)
{
	if (backup_map->content[y][x] == '1')
		return ;
	else if (backup_map->content[y][x] == 'C')
	{
		backup_map->content[y][x] = '1';
		backup_map->collectibles++;
	}
	else if (backup_map->content[y][x] == 'E')
	{
		backup_map->content[y][x] = '1';
		backup_map->exit.x++;
		return ;
	}
	backup_map->content[y][x] = '1';
	floodfill(backup_map, x + 1, y);
	floodfill(backup_map, x - 1, y);
	floodfill(backup_map, x, y + 1);
	floodfill(backup_map, x, y - 1);
}

void	check_path(t_game *game)
{
	t_map	*backup_map;
	int		i;

	backup_map = malloc(sizeof(t_map));
	if (!backup_map)
		error("malloc in check_path failed", game);
	backup_map->collectibles = 0;
	backup_map->exit.x = 0;
	backup_map->content = game->map.content;
	floodfill(backup_map, game->map.spawn.x, game->map.spawn.y);
	if (backup_map->collectibles != game->map.collectibles
		|| !backup_map->exit.x)
	{
		free(backup_map);
		error("Every components doesn't have a path", game);
	}
	i = 0;
	while (i < game->map.rows)
		free((backup_map->content[i++]));
	free(backup_map->content);
	free(backup_map);
}
