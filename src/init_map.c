/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:12:07 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/21 15:37:01 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_parsing(t_game *game, t_map *map, char *map_file)
{
	int		fd;
	char	*line;
	char	*content;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		error("Map opening failed", game);
	content = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line && ft_strlen(content) == 0)
			error("Map is empty", game);
		if (!line)
			break ;
		content = ft_strappend(&content, line);
	}
	close(fd);
	map->content = ft_split(content, '\n');
	free(content);
	return (1);
}

int	init_map(t_game *game, t_map *map, char *map_file)
{
	if (!ft_strnstr(map_file + ft_strlen(map_file) - 4, ".ber", 4))
		error("Not a .ber file", game);
	map_parsing(game, map, map_file);
	game->map = map;
	game->map->collumns = ft_strlen(map->content[0]);
	game->map->rows = (ft_strlen(map->content[0]) - 1);
	game->map->collectibles = 0;
	valid_map_content(game, game->map);
	rectangular_map(game, game->map);
	walls_surround(game, game->map);
	specials_components(game);
	check_path(game);
	return (1);
}
