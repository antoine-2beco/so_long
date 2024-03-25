/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:16:06 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/25 10:54:22 by ade-beco         ###   ########.fr       */
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

	backup_map = malloc(sizeof(t_map));
	if (!backup_map)
		error("malloc in check_path failed", game);
	backup_map->collectibles = 0;
	backup_map->exit.x = 0;
	backup_map->content = game->map->content;
	floodfill(backup_map, game->map->spawn.x, game->map->spawn.y);
	if (backup_map->collectibles != game->map->collectibles
		|| !backup_map->exit.x)
	{
		free(backup_map);
		error("Every components doesn't have a path", game);
	}
	ft_printf("1");
	i = 0;
	while (i < game->map->rows)
		free((backup_map->content[i++]));
	ft_printf("2");
	free(backup_map->content);
	ft_printf("3");
	free(backup_map);
	return (1);
}
