/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:01:13 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/12 11:09:23 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

int	main(int argc, char *argv[])
{
	//void	*mlx;
	//void	*mlx_win;

	if (argc != 2)
		return (0);
	check_map(argv[1]);
	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	//mlx_loop(mlx);
	//ft_printf("Hello %i\n", argc);
	//while (*argv++)
	//	ft_printf("%s\n", *argv);
}
