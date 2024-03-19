/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:16:06 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/19 18:07:10 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	floodfill(t_map *map, int x, int y)
{
	if (map->content[y][x] == '1')
		return (1);
	else if (map->content[y][x] == 'C')
	{
		map->content[y][x] = '1';
		map->collectibles++;
	}
	else if (map->content[y][x] == 'E')
	{
		map->content[y][x] = '1';
		map->exit.x++;
		return (1);
	}
	map->content[y][x] = '1';
	floodfill(map, x + 1, y);
	floodfill(map, x - 1, y);
	floodfill(map, x, y + 1);
	floodfill(map, x, y - 1);
	return (1);
}

int	check_path(t_game *game)
{
	t_map	*backup_map;
	int		i;
	int		j;

	backup_map = malloc(sizeof(t_map));
	backup_map->collectibles = 0;
	backup_map->exit.x = 0;
	backup_map->content = game->map->content;
	i = 0;
	j = 0;
	floodfill(backup_map, game->map->spawn.x, game->map->spawn.y);
	if (backup_map->collectibles != game->map->collectibles
		|| !backup_map->exit.x)
	{
		free(backup_map);
		j = 1;
	}
	while (i < game->map->rows)
		free((backup_map->content[i++]));
	free(backup_map->content);
	free(backup_map);
	if (j)
		return (error("Every components doesn't have a path"));
	return (1);
}
