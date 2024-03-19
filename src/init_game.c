/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:32:19 by ade-beco          #+#    #+#             */
/*   Updated: 2024/03/19 18:33:21 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(game->mlx);
}
