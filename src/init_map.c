/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:12:07 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/28 15:16:15 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_compliant(t_list **map)
{
	if (!valid_map_content(map))
		return (0);
	if (!rectangular_map(map))
		return (0);
	return (1);
}

static int	map_parsing(t_list **map, char *map_file)
{
	int		fd;
	char	*line;
	int		l;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (error("Map opening failed"));
	l = -1;
	while (l++ >= -1)
	{
		line = get_next_line(fd);
		if (!line && l == 0)
			return (error("Map is empty"));
		if (!line)
			break ;
		ft_lstadd_back(map, ft_lstnew(line));
	}
	return (1);
}

int	init_map(t_list **map, char *map_file)
{
	if (!ft_strnstr(map_file + ft_strlen(map_file) - 4, ".ber", 4))
		return (error("Not a .ber file"));
	if (!map_parsing(map, map_file))
		return (0);
	if (!map_compliant(map))
		return (0);
	return (1);
}

// error system

// rectangular

// walls
// one spawn
// one exit
// one collectible
// valid path