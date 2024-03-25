/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_compliant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:58:33 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/25 17:34:31 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	valid_map_content(t_game *game)
{
	char	*str;
	int		x;
	int		y;

	y = 0;
	while (game->map.content[y])
	{
		x = 0;
		str = game->map.content[y];
		while (str[x])
		{
			if (str[x] != FLOOR && str[x] != WALL
				&& str[x] != COLLECTIBLE && str[x] != EXIT
				&& str[x] != PLAYER && str[x] != '\n')
				error("Bad map content", game);
			if (str[x] == '\n' && x == 0)
				error("Bad newline", game);
			x++;
		}
		y++;
	}
}

void	rectangular_map(t_game *game)
{
	char	*line;
	int		lenght;
	int		y;

	y = 0;
	line = ft_strtrim(game->map.content[y], "\n");
	if (!line)
		error ("Malloc failed in ft_strtrim", game);
	lenght = ft_strlen(line);
	free (line);
	while (game->map.content[y])
	{
		line = ft_strtrim(game->map.content[y], "\n");
		if (!line)
			error ("Malloc failed in ft_strtrim", game);
		if (lenght != (int)(ft_strlen(line)))
			error("Map is not rectangular", game);
		free (line);
		y++;
	}
}

void	walls_surround(t_game *game)
{
	int		y;
	int		x;

	y = 1;
	x = 0;
	while (game->map.content[0][x])
		if (game->map.content[0][x++] != WALL)
			error("Walls aren't surrounding the map", game);
	while (game->map.content[y + 1])
	{
		if ((game->map.content[y][0] != WALL)
			|| (game->map.content[y][game->map.collumns - 1] != WALL))
			error("Walls aren't surrounding the map", game);
		y++;
	}
	while (game->map.content[y][x])
		if (game->map.content[y][x++] != WALL)
			error("Walls aren't surrounding the map", game);
}

static void	saving_components(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->map.content[y])
	{
		x = 0;
		while (game->map.content[y][x])
		{
			if (game->map.content[y][x] == EXIT)
			{
				game->map.exit.x = x;
				game->map.exit.y = y;
			}
			if (game->map.content[y][x] == PLAYER)
			{
				game->map.player.x = x;
				game->map.player.y = y;
			}
			x++;
		}
		y++;
	}
}

void	specials_components(t_game *game)
{
	int		exit_player;
	int		y;
	int		x;

	exit_player = 0;
	y = 0;
	while (game->map.content[y])
	{
		x = 0;
		while (game->map.content[y][x])
		{
			if ((game->map.content[y][x] == EXIT)
				|| (game->map.content[y][x] == PLAYER))
				exit_player++;
			if (game->map.content[y][x] == COLLECTIBLE)
				game->map.collectibles++;
			x++;
		}
		y++;
	}
	if (exit_player != 2 || game->map.collectibles < 1)
		error("Map components problem", game);
	saving_components(game);
}
