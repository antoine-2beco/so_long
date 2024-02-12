/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:01:13 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/12 15:54:53 by ade-beco         ###   ########.fr       */
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
	int		ret;
	t_list	*map;
	//void	*mlx;
	//void	*mlx_win;

	ret = 1;
	map = NULL;
	if (argc != 2)
		ret = error ("Bad argument");
	if (ret && !check_map(&map, argv[1]))
		ret = 0;

	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	//mlx_loop(mlx);
}
