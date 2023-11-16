/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:20:05 by aabouqas          #+#    #+#             */
/*   Updated: 2023/11/16 18:24:17 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_strlen(const char *s);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_itoa(int num);
int	ft_base(unsigned int num, char *base);
int	ft_pointer(unsigned long p);
int	ft_unsigned(unsigned int num);

#endif
