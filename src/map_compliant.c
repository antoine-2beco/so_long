/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_compliant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:58:33 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/11 12:44:54 by ade-beco         ###   ########.fr       */
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

#include <stdio.h>
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
