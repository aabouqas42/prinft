/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:11:54 by aabouqas          #+#    #+#             */
/*   Updated: 2023/11/16 13:20:33 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int check;

	check = 0;
	i = 0;
	if (!str)
	{
		check = write (1, "(null)", 6);
		if (check == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		check = ft_putchar((int)str[i]);
		if (check == -1)
			return (-1);
		i++;
	}
	return (i);
}
