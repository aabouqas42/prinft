/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:31:41 by aabouqas          #+#    #+#             */
/*   Updated: 2023/11/16 13:23:21 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	ft_unsigned(unsigned int num)
{
	char	*str;
	int		len;

	if (num == 0)
		return (ft_putchar('0'));
	if (num < 0)
		num = 4294967295 + num;
	len = ft_numlen(num);
	str = malloc (len + 1);
	if (!str)
		return (-1);
	str[len] = '\0';
	len--;
	while (num)
	{
		str[len] = (num % 10) + 48;
		num /= 10;
		len--;
	}
	ft_putstr(str);
	len = ft_strlen(str);
	free (str);
	return (len);
}
