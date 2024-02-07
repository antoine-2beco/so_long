/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:07 by ade-beco          #+#    #+#             */
/*   Updated: 2024/02/07 10:15:13 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_treat_dec(long long int nbr)
{
	int	c;
	int	j;

	c = 0;
	if (nbr < 0)
	{
		if (ft_printf_putchar('-') == -1)
			return (-1);
		nbr *= -1;
		c++;
	}
	j = ft_printf_base(nbr, 10, 0);
	if (j == -1)
		return (-1);
	return (c + j);
}

static int	ft_treat_void(long long int nbr)
{
	int	j;

	if (ft_printf_putstr("0x", 0) == -1)
		return (-1);
	j = ft_printf_base((unsigned long long)nbr, 16, 1);
	if (j == -1)
		return (-1);
	return (2 + j);
}

static int	ft_specifics(const char *str, int i, va_list arg)
{
	int	j;

	if (str[i] == '%' && str[i + 1] == 'c')
		j = ft_printf_putchar((char)(va_arg(arg, int)));
	else if (str[i] == '%' && str[i + 1] == 's')
		j = ft_printf_putstr((char *)va_arg(arg, char *), 0);
	else if (str[i] == '%' && str[i + 1] == 'p')
		j = ft_treat_void(va_arg(arg, unsigned long long));
	else if (str[i] == '%' && str[i + 1] == 'd')
		j = ft_treat_dec(va_arg(arg, int));
	else if (str[i] == '%' && str[i + 1] == 'i')
		j = ft_treat_dec(va_arg(arg, int));
	else if (str[i] == '%' && str[i + 1] == 'u')
		j = ft_treat_dec(va_arg(arg, unsigned int));
	else if (str[i] == '%' && str[i + 1] == 'x')
		j = ft_printf_base(va_arg(arg, unsigned int), 16, 1);
	else if (str[i] == '%' && str[i + 1] == 'X')
		j = ft_printf_base(va_arg(arg, unsigned int), 16, 0);
	else if (str[i] == '%' && str[i + 1] == '%')
		j = ft_printf_putchar('%');
	else
		return (-2);
	return (j);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		c;
	int		j;

	i = -1;
	c = 0;
	va_start(arg, str);
	while (str[++i] != '\0')
	{
		j = ft_specifics(str, i, arg);
		if (j == -2 && str[i] != '%' && ft_printf_putchar(str[i]) != -1)
			c++;
		else if (j != -1 && j != -2)
		{
			c += j;
			i++;
		}
		else
			return (-1);
	}
	va_end(arg);
	return (c);
}
