/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:38:18 by aabouqas          #+#    #+#             */
/*   Updated: 2023/11/16 18:42:34 by aabouqas         ###   ########.fr       */
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
		return (ft_itoa(va_arg(args, int)));
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

static int	ft_helper(const char *str, va_list args)
{
	int	check;
	int	len;

	len = 0;
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
		}
		else if (*str)
		{
			if (ft_putchar((int)*str) == -1)
				return (-1);
			len++;
			str++;
		}
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		check;
	va_list	args;

	va_start (args, str);
	len = 0;
	check = ft_helper(str, args);
	if (check == -1)
		return (-1);
	else
		len = check;
	va_end(args);
	return (len);
}
