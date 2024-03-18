/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:12:07 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/18 14:41:24 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_compliant(t_game *game)
{
	if (!valid_map_content(game->map))
		return (0);
	if (!rectangular_map(game->map))
		return (0);
	if (!walls_surround(game->map))
		return (0);
	if (!specials_components(game))
		return (0);
	if (!check_path(game))
		return (0);
	return (1);
}

static int	map_parsing(t_map *map, char *map_file)
{
	int		fd;
	char	*line;
	char	*content;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (error("Map opening failed"));
	content = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line && ft_strlen(content) == 0)
			return (error("Map is empty"));
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
		return (error("Not a .ber file"));
	if (!map_parsing(map, map_file))
		return (0);
	game->map = map;
	game->map->collumns = ft_strlen(map->content[0]);
	game->map->rows = (ft_strlen(map->content[0]) - 1);
	game->map->collectibles = 0;
	if (!map_compliant(game))
		return (0);
	return (1);
}
