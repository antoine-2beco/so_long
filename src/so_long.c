/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:01:13 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/19 18:34:16 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error(char *str)
{
	ft_printf("Error\n%s\n", str);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	*game;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	game = (t_game *)malloc(sizeof(t_game));
	if (!game || !map)
		return (error("Struct malloc failed"));
	if (argc != 2)
		return (error("Bad argument"));
	if (!init_map(game, map, argv[1]))
		return (0);
	if (!init_mlx(game))
		return (0);
	return (1);
}
