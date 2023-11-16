/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:50:24 by aabouqas          #+#    #+#             */
/*   Updated: 2023/11/16 16:14:00 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	baselen(unsigned long num)
{
	int	len;

	len = 0;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	ft_pointer(unsigned long p)
{
	char	*str;
	char	*base;
	int		len;
	int		check;

	check = 0;
	if (p == 0)
		return (ft_putstr("0x0"));
	base = "0123456789abcdef";
	len = baselen(p);
	str = malloc (len + 1);
	if (!str)
		return (-1);
	str[len--] = '\0';
	check = ft_putstr ("0x");
	if (check == -1)
		return (-1);
	while (p)
	{
		str[len] = base[p % 16];
		p /= 16;
		len--;
	}
	len = ft_strlen(str);
	check = ft_putstr(str);
	if (check == -1 || !len)
	{
		free (str);
		return (-1);
	}
	free (str);
	return (len + 2);
}
