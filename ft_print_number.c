/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:02:46 by aabouqas          #+#    #+#             */
/*   Updated: 2023/11/20 14:58:29 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len++;
		num *= (-1);
	}
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static int	ft_helper(char *str, int num, int len)
{
	while (num)
	{
		str[len] = (num % 10) + 48;
		num /= 10;
		len--;
	}
	if (ft_putstr(str) == -1)
	{
		free (str);
		return (-1);
	}
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	ft_print_number(int num)
{
	char	*str;
	int		len;

	if (num == 0)
		return (ft_putchar('0'));
	if (num == -2147483648)
		return (ft_putstr("-2147483648"));
	len = ft_numlen(num);
	str = malloc (len + 1);
	if (!str)
		return (-1);
	if (num < 0)
	{
		str[0] = '-';
		num *= (-1);
	}
	str[len] = '\0';
	return (ft_helper(str, num, len - 1));
}
