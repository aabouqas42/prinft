/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:38:18 by aabouqas          #+#    #+#             */
/*   Updated: 2023/11/16 15:56:25 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handler(va_list args ,const char c)
{
	if (c == 's')
		return (ft_putstr (va_arg(args, char *)));
	if (c == 'c')
		return (ft_putchar (va_arg(args, int)));
	if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(args, int)));
	if (c == 'x')
		return (ft_base(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_base(va_arg(args, unsigned int), 1));
	if (c == 'p')
		return( ft_pointer(va_arg(args, unsigned long)));
	if (c == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (ft_putchar(c));
}

int ft_printf(const char *str, ...)
{
	int		len;
	int		check;

	len = 0;
	check = 1;
	va_list	args;
	va_start (args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			check = handler(args, *str);
			if (check == -1)
				return (-1);
			len += check;
			str++;
		} else if (*str)
		{
			check = ft_putchar((int)*str);
			if (check == -1)
				return (-1);
			len += check;
			str++;
		}
	}
	va_end(args);
	return ((int)len);
}
