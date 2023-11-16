#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

// delete it
#include <stdio.h>

int	ft_printf(const char *, ...);
int	ft_strlen(const char *s);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_itoa(int num);
int	ft_base(unsigned int num, char *base);
int	ft_pointer(unsigned long p);
int	ft_unsigned(unsigned int num);

#endif
