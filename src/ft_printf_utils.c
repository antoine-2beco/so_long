/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:54:06 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/07 10:15:17 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_printf_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_printf_putstr(char *s, int lower)
{
	int	l;
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (!s)
		return (ft_printf_putstr("(null)", 0));
	l = ft_strlen(s);
	while (i < l)
	{
		if (lower)
			s[i] = ft_tolower(s[i]);
		if (ft_printf_putchar(s[i++]) == -1)
			return (-1);
		c++;
	}
	return (c);
}

static int	ft_lenght_nbr(unsigned long long nbr, int base_lenght)
{
	unsigned long long	nb;
	int					lenght;

	lenght = 0;
	if (nbr < 0)
	{
		nb = nbr * -1;
		lenght++;
	}
	else
		nb = nbr;
	while (nb >= (unsigned)base_lenght)
	{
		nb /= base_lenght;
		lenght++;
	}
	lenght++;
	return (lenght);
}

static char	*ft_convert_nbr_base(unsigned long long a,
	int base, char *res, int i)
{
	while (a != 0)
	{
		if ((a % base) < 10)
			res[i - 1] = (a % base) + 48;
		else
			res[i - 1] = (a % base) + 55;
		a /= base;
		i--;
	}
	return (res);
}

int	ft_printf_base(unsigned long long nbr, int base, int lower)
{
	char	*res;
	int		res_lenght;
	int		c;

	if (nbr == 0)
		return (ft_printf_putchar('0'));
	res_lenght = ft_lenght_nbr(nbr, base);
	res = malloc(sizeof(char) * (res_lenght + 1));
	if (!res)
		return (-1);
	res = ft_convert_nbr_base(nbr, base, res, res_lenght);
	res[res_lenght] = '\0';
	c = ft_printf_putstr(res, lower);
	free(res);
	return (c);
}
