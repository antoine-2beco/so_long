/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:01:15 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/07 15:29:54 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
#include <mlx.h>

// ft_printf && ft_printf_utils
int		ft_printf(const char *str, ...);
int		ft_printf_putchar(char c);
int		ft_printf_putstr(char *s, int lower);
int		ft_printf_base(unsigned long long nbr, int base, int lower);

// utils_func
size_t	ft_strlen(const char *s);
int		ft_tolower(int c);

#endif