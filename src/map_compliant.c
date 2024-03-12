/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_compliant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:58:33 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/12 15:55:28 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_map_content(t_list **map)
{
	t_list	*temp;
	char	*str;
	int		i;

	temp = *map;
	while (temp)
	{
		i = 0;
		str = temp->content;
		while (str[i])
		{
			if (str[i] != '0' && str[i] != '1'
				&& str[i] != 'C' && str[i] != 'E'
				&& str[i] != 'P' && str[i] != '\n')
				return (error("Bad map content"));
			if (str[i] == '\n' && i == 0)
				return (error("Bad newline"));
			i++;
		}
		temp = temp->next;
	}
	return (1);
}

int	rectangular_map(t_list **map)
{
	t_list	*temp;
	char	*line;
	int		lenght;

	temp = *map;
	line = ft_strtrim(temp->content, "\n");
	if (!line)
		error ("Malloc failed in ft_strtrim");
	lenght = ft_strlen(line);
	free (line);
	while (temp)
	{
		line = ft_strtrim(temp->content, "\n");
		if (!line)
			error ("Malloc failed in ft_strtrim");
		if (lenght != (int)(ft_strlen(line)))
			return (error("Map is not rectangular"));
		free (line);
		temp = temp->next;
	}
	return (1);
}

int	walls_surround(t_list **map, int map_lenght)
{
	t_list	*temp;
	int		i;

	temp = *map;
	i = 0;
	while (i < map_lenght)
		if (((char *)temp->content)[i++] != '1')
			return (error("Walls aren't surrounding the map"));
	while (temp->next)
	{
		if (((char *)temp->content)[0] != '1'
			|| ((char *)temp->content)[map_lenght - 1] != '1')
			return (error("Walls aren't surrounding the map"));
		temp = temp->next;
	}
	i = 0;
	while (i < map_lenght)
		if (((char *)temp->content)[i++] != '1')
			return (error("Walls aren't surrounding the map"));
	return (1);
}

static int	saving_components(t_game **game)
{
	t_list	*temp;
	int		x;
	int		y;

	temp = (*game)->map;
	y = 0;
	while (temp)
	{
		x = -1;
		while (x++ < ((*game)->map_lenght - 1))
		{
			if (((char *)temp->content)[x] == 'E')
			{
				(*game)->x_exit = x;
				(*game)->y_exit = y;
			}
			if (((char *)temp->content)[x] == 'P')
			{
				(*game)->x_spawn = x;
				(*game)->y_spawn = y;
			}
		}
		temp = temp->next;
		y++;
	}
	return (1);
}

int	specials_components(t_game **game)
{
	t_list	*temp;
	int		i;
	int		exit_spawn;

	temp = (*game)->map;
	exit_spawn = 0;
	while (temp)
	{
		i = 0;
		while (i < (*game)->map_lenght)
		{
			if (((char *)temp->content)[i] == 'E'
				|| ((char *)temp->content)[i] == 'P')
				exit_spawn++;
			if (((char *)temp->content)[i++] == 'C')
				(*game)->collectibles++;
		}
		temp = temp->next;
	}
	if (exit_spawn != 2 || (*game)->collectibles < 1)
		return (error("Map components problem"));
	saving_components(game);
	return (1);
}
