/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:29:27 by aabouqas          #+#    #+#             */
/*   Updated: 2023/11/16 13:24:34 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	baselen(unsigned int num)
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

int	ft_base(unsigned int num, int up)
{
	char	*base;
	char	*str;
	int		len;

	if (num == 0)
		return (ft_putchar('0'));
	len = baselen(num);
	base = "0123456789abcdef";
	if (up)
		base = "0123456789ABCDEF";
	str = malloc (len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	len--;
	while (num)
	{
		str[len] = base[num % 16];
		num /= 16;
		len--;
	}
	len = ft_strlen(str);
	ft_putstr(str);
	free (str);
	return (len);
}
