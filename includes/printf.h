#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(const char c);
void	process_format(char **ptr, unsigned int *char_printed);
int		ft_isdigit(const char c);
int		isflag(const char c);
int		ft_atoi(const char *str);
#endif
