/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:12:07 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/12 12:00:31 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

static int	map_parsing(t_list **map, char *map_file)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (!fd)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(map, ft_lstnew(line));
	}
	return (1);
}

int	check_map(char *map_file)
{
	t_list	*map;

	map_parsing(&map, map_file);
	while (map)
	{
		ft_printf("%s", map->content);
		map = map->next;
	}
	return (1);
}

// error system
// .ber file
// walls
// one spawn
// one exit
// one collectible
// valid path
// not empty
// valid content
// rectangular