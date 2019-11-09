/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:31:58 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/09 09:53:40 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

unsigned int	putstr(char *s, unsigned int width, int size,
		int flags[2])
{
	unsigned int length;
	unsigned int fill;
	unsigned int i;

	if (!s)
		return (putstr("(null)", width, size, flags));
	length = ft_strlen(s);
	if (size >= 0)
		length = min((size < 0 ? -size : size), ft_strlen(s));
	if (width == 0 || width < length)
		fill = 0;
	else
		fill = width - length;
	if (!flags[0] && fill > 0)
		ft_putcharn_fd((flags[1] ? '0' : ' '), fill);
	i = 0;
	while (i < length)
		ft_putchar_fd(s[i++], 1);
	i = 0;
	if (flags[0] && fill > 0)
		ft_putcharn_fd((flags[1] ? '0' : ' '), fill);
	return (fill + length);
}

unsigned int	putchar_(char c, unsigned int width, int size,
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
			ft_putchar_fd((flags[1] ? '0' : ' '), 1);
	}
	ft_putchar_fd(c, 1);
	if (flags[0] && fill > 0)
	{
		while (i++ < fill)
			ft_putchar_fd((flags[1] ? '0' : ' '), 1);
	}
	(void)size;
	return (fill + 1);
}

unsigned int	putnbr(long int n, unsigned int width, int size,
		int flags[2])
{
	char			*a;
	int				fill_z;
	int				fill_s;
	unsigned int	s;

	if (n == 0 && size == 0)
		a = ft_calloc(1, sizeof(char));
	else
		a = ft_itoa(abs_(n));
	s = ft_strlen(a);
	fill_z = 0;
	fill_s = 0;
	if (size > (int)s + (n < 0 ? 1 : 0))
		fill_z = size - s;
	if (flags[1] && width > s + (n < 0 ? 1 : 0) && size == -1)
		fill_z = width - s - (n < 0 ? 1 : 0);
	if (width > fill_z + s + (n < 0 ? 1 : 0))
		fill_s = width - (fill_z + s + (n < 0 ? 1 : 0));
	if (!flags[0])
		ft_putcharn_fd(' ', fill_s);
	if (n < 0)
		ft_putchar_fd('-', 1);
	ft_putcharn_fd('0', fill_z);
	ft_putstr_fd(a, 1);
	if (flags[0])
		ft_putcharn_fd(' ', fill_s);
	free(a);
	return (s + fill_z + fill_s + (n < 0));
}

unsigned int	putunbr(long int n, unsigned int width, int size,
						int flags[2])
{
	long int nb;

	nb = n;
	if (n < 0)
		nb = 4294967296 + n;
	return (putnbr(nb, width, size, flags));
}
unsigned int	puthex(long int n, unsigned int width, int size,
						int flags[2], int caps)
{
	char			*a;
	int				fill_z;
	int				fill_s;
	int				i;
	unsigned int	s;

	if (n < 0)
		n = 4294967296 + n;
	if (n == 0 && size == 0)
		a = ft_calloc(1, sizeof(char));
	else
		a = ft_itoa_hex(abs_(n), caps);
	s = ft_strlen(a);
	fill_z = 0;
	fill_s = 0;
	if (size > (int)s)
		fill_z = size - s;
	if (flags[1] && (int)width > size && size == -1)
		fill_z = width - s;
	if (width > fill_z + s)
		fill_s = width - (s + fill_z) - (n < 0);
	else
		fill_s = 0;
	i = 0;
	while (!flags[0] && i++ < fill_s)
		ft_putchar_fd(' ', 1);
	if (n < 0)
		ft_putchar_fd('-', 1);
	i = 0;
	while (i++ < fill_z)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(a, 1);
	i = 0;
	while (flags[0] && i++ < fill_s)
		ft_putchar_fd(' ', 1);
	free(a);
	return (s + (fill_z > 0 ? fill_z : 0) + (fill_s > 0 ? fill_s : 0));
}
