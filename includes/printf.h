/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:17:14 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/06 16:33:10 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int					ft_printf(const char *format, ...);
int					isflag(const char c);
unsigned int		putstr(char *s, unsigned int width, int size,
		int flags[2]);
void				get_flags(char **ptr, int flags[2]);
int					get_width(char **ptr);
int					get_size(char **ptr);
int					min(int a, int b);
int					max(int a, int b);
unsigned int		putchar_(char c, unsigned int width, int size,
		int flags[2]);
unsigned int		putnbr(long int n, unsigned int width, int size,
		int flags[2]);
unsigned int		putunbr(long int n, unsigned int width, int size,
		int flags[2]);
unsigned int		puthex(long int n, unsigned int width, int size,
		int flags[2], int caps);
unsigned int		abs_(long int n);
char				*ft_itoa_hex(unsigned long int n, int caps);
unsigned int		putptr(void *ptr, unsigned int width, int size,
		int flags[2]);
void				replace_stars(char **format, ...);
void				replace_first_star(char **src, int n);
int					is_type(const char c);
int					count_stars(char *str);
int					handle_format(char **ptr, va_list args);
int					handle_format_star(char **ptr, int arg, va_list args);
int					handle_format_star2(char **ptr, int arg1, int arg2, va_list args);
int					process(char type, int flags[2], int width, int size, va_list args);
#endif
