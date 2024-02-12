/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:01:13 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/12 13:06:35 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"


int	main(int argc, char *argv[])
{
	t_list *map;
	//void	*mlx;
	//void	*mlx_win;

	map = NULL;
	if (argc != 2)
		perror("Bad argument");
	check_map(&map, argv[1]);

	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	//mlx_loop(mlx);
}
