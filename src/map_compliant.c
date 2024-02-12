/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_compliant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:58:33 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/12 16:33:38 by ade-beco         ###   ########.fr       */
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
//			if (str[i] == '\n' && str[i + 1] == '\n')
//					return (error("Many \n in a row"));
			i++;
		}
		temp = temp->next;
	}
	return (1);
}
