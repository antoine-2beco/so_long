/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_compliant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:58:33 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/18 14:41:12 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_map_content(t_map *map)
{
	char	*str;
	int		x;
	int		y;

	y = 0;
	while (map->content[y])
	{
		x = 0;
		str = map->content[y];
		while (str[x])
		{
			if (str[x] != '0' && str[x] != '1'
				&& str[x] != 'C' && str[x] != 'E'
				&& str[x] != 'P' && str[x] != '\n')
				return (error("Bad map content"));
			if (str[x] == '\n' && x == 0)
				return (error("Bad newline"));
			x++;
		}
		y++;
	}
	return (1);
}

int	rectangular_map(t_map *map)
{
	char	*line;
	int		lenght;
	int		y;

	y = 0;
	line = ft_strtrim(map->content[y], "\n");
	if (!line)
		error ("Malloc failed in ft_strtrim");
	lenght = ft_strlen(line);
	free (line);
	while (map->content[y])
	{
		line = ft_strtrim(map->content[y], "\n");
		if (!line)
			error ("Malloc failed in ft_strtrim");
		if (lenght != (int)(ft_strlen(line)))
			return (error("Map is not rectangular"));
		free (line);
		y++;
	}
	return (1);
}

int	walls_surround(t_map *map)
{
	int		y;
	int		x;

	y = 1;
	x = 0;
	while (map->content[0][x])
		if (map->content[0][x++] != '1')
			return (error("Walls aren't surrounding the map"));
	while (map->content[y + 1])
	{
		if ((map->content[y][0] != '1')
			|| (map->content[y][map->collumns - 1] != '1'))
			return (error("Walls aren't surrounding the map"));
		y++;
	}
	while (map->content[y][x])
		if (map->content[y][x++] != '1')
			return (error("Walls aren't surrounding the map"));
	return (1);
}

static int	saving_components(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->map->content[y])
	{
		x = 0;
		while (game->map->content[y][x])
		{
			if (game->map->content[y][x] == 'E')
			{
				game->map->exit.x = x;
				game->map->exit.y = y;
			}
			if (game->map->content[y][x] == 'P')
			{
				game->map->spawn.x = x;
				game->map->spawn.y = y;
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	specials_components(t_game *game)
{
	int		exit_spawn;
	int		y;
	int		x;

	exit_spawn = 0;
	y = 0;
	while (game->map->content[y])
	{
		x = 0;
		while (game->map->content[y][x])
		{
			if ((game->map->content[y][x] == 'E')
				|| (game->map->content[y][x] == 'P'))
				exit_spawn++;
			if (game->map->content[y][x] == 'C')
				game->map->collectibles++;
			x++;
		}
		y++;
	}
	if (exit_spawn != 2 || game->map->collectibles < 1)
		return (error("Map components problem"));
	saving_components(game);
	return (1);
}
