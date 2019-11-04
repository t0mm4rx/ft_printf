/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:17:14 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/04 09:40:38 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int					ft_printf(const char *format, ...);
void				process_format(char **ptr, unsigned int *char_printed);
int					isflag(const char c);
unsigned int		putstr(char *s, unsigned int width, unsigned int size,
		int flags[2]);
int					min(int a, int b);
unsigned int		putchar_(char c, unsigned int width, unsigned int size,
		int flags[2]);
unsigned int		putnbr(long int n, unsigned int width, unsigned int size,
		int flags[2]);
unsigned int		putunbr(long int n, unsigned int width, unsigned int size,
		int flags[2]);
unsigned int		abs_(long int n);
#endif
