/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_compliant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:58:33 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/27 17:31:53 by ade-beco         ###   ########.fr       */
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
	int		i;
	int		j;
	int		k;
	char	*line;
	t_list	*temp;

	temp = *map;
	k = -1;
	while (temp && k++ >= -1)
	{
		line = temp->content;
		j = 0;
		while (line[j])
		{
			if (j == INT32_MAX && line[j + 1])
				return (error("Map exceed maximal size"));
			j++;
		}
		printf("line = %s -- i = %i -- j = %i\n", line, i, j);
		if ((j != i && i))
			return (error("Map is not rectangular"));
		if (k == INT32_MAX && temp->next)
			return (error("Map exceed maximal size"));
		i = j;
		temp = temp->next;
	}
	return (1);
}
