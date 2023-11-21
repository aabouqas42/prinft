/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:38:18 by aabouqas          #+#    #+#             */
/*   Updated: 2023/11/17 17:44:55 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handler(va_list args, const char c)
{
	if (c == 's')
		return (ft_putstr (va_arg(args, char *)));
	if (c == 'c')
		return (ft_putchar (va_arg(args, int)));
	if (c == 'd' || c == 'i')
		return (ft_print_number(va_arg(args, int)));
	if (c == 'x')
		return (ft_base(va_arg(args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (c == 'p')
		return (ft_pointer(va_arg(args, unsigned long)));
	if (c == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (ft_putchar(c));
}

static int	print(const char *str, va_list args)
{
	int	got;
	int	len;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
			{
				got = handler(args, *str++);
				if (got == -1)
					return (-1);
				len += got;
			}
		}
		else if (*str)
		{
			if (ft_putchar((int)*str++) == -1)
				return (-1);
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	va_start (args, str);
	len = print(str, args);
	va_end(args);
	return (len);
}
