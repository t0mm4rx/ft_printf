/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:31:58 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/28 15:40:53 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned int	putstr(char *s, unsigned int width, unsigned int size,
		int flags[2])
{
	unsigned int length;
	unsigned int fill;
	unsigned int i;

	i = 0;
	length = min((size < 0 ? -size : size), ft_strlen(s));
	if (width == 0 || width < length)
		fill = 0;
	else
		fill = width - length;
	if (!flags[0] && fill > 0)
	{
		while (i++ < fill)
			ft_putchar((flags[1] ? '0' : ' '));
	}
	i = 0;
	while (i < length)
		ft_putchar(s[i++]);
	i = 0;
	if (flags[0] && fill > 0)
	{
		while (i++ < fill)
			ft_putchar((flags[1] ? '0' : ' '));
	}
	return (fill + length);
}

unsigned int	putchar2(char c, unsigned int width, unsigned int size,
		int flags[2])
{
	unsigned int i;
	unsigned int fill;

	i = 0;
	fill = 0;
	if (width > 1)
		fill = width - 1;
	if (!flags[0] && fill > 0)
	{
		while (i++ < fill)
			ft_putchar((flags[1] ? '0' : ' '));
	}
	ft_putchar(c);
	if (flags[0] && fill > 0)
	{
		while (i++ < fill)
			ft_putchar((flags[1] ? '0' : ' '));
	}(void)size;
	return (fill + 1);
}