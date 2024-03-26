/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:12:07 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/26 13:42:35 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	map_parsing(t_game *game, char *map_file)
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
		free(line);
		if (!content)
			error("ft_strappend failed");
	}
	close(fd);
	game->map.content = ft_split(content, '\n');
	free(content);
	if (!game->map.content)
		error("ft_split failed", game);
}

void	init_map(t_game *game, char *map_file)
{
	if (!ft_strnstr(map_file + ft_strlen(map_file) - 4, ".ber", 4))
		error("Not a .ber file", game);
	map_parsing(game, map_file);
	game->map_alloc = 1;
	game->movements = 0;
	game->map.collectibles = 0;
	game->map.collumns = ft_strlen(game->map.content[0]);
	game->map.rows = 0;
	while (game->map.content[game->map.rows])
		game->map.rows++;
	valid_map_content(game);
	rectangular_map(game);
	walls_surround(game);
	specials_components(game);
	check_path(game);
	map_parsing(game, map_file);
}
