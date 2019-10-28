/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:17:14 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/28 15:18:21 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int					ft_printf(const char *format, ...);
void				ft_putchar(const char c);
void				process_format(char **ptr, unsigned int *char_printed);
int					ft_isdigit(const char c);
int					isflag(const char c);
int					ft_atoi(const char *str);
unsigned int		putstr(char *s, unsigned int width, unsigned int size,
		int flags[2]);
unsigned int		ft_strlen(char *str);
int					min(int a, int b);
#endif
