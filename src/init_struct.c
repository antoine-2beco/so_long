/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:33:13 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/25 13:16:16 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*init_struct(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error("Game struct malloc failed", NULL);
	game->map_alloc = 0;
	//map = (t_map *)malloc(sizeof(t_map));
	//if (!map)
	//	error("Map struct malloc failed", game);
	//game->map_alloc = 1;
	//game->map = map;
	return (game);
}
