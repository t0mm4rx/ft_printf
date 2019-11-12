/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:31:58 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/12 11:21:22 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

unsigned int	putstr(char *s, t_params params)
{
	unsigned int length;
	unsigned int fill;
	unsigned int i;

	if (!s)
		return (putstr("(null)", params));
	length = ft_strlen(s);
	if (params.size >= 0)
	{
		length = min((params.size < 0 ? -params.size : params.size),
				ft_strlen(s));
	}
	if (abs_(params.width) == 0 || abs_(params.width) < (int)length)
		fill = 0;
	else
		fill = abs_(params.width) - length;
	if ((!params.flags[0] && params.width >= 0) && fill > 0)
		ft_putcharn_fd((params.flags[1] ? '0' : ' '), fill);
	i = 0;
	while (i < length)
		ft_putchar_fd(s[i++], 1);
	i = 0;
	if ((params.flags[0] || params.width < 0) && fill > 0)
		ft_putcharn_fd((params.flags[1] ? '0' : ' '), fill);
	return (fill + length);
}

unsigned int	putchar_(char c, t_params params)
{
	int fill;

	fill = 0;
	if (params.width != 0)
		fill = abs_(params.width) - 1;
	fill = abs_(fill);
	if (!params.flags[0] && params.width > 0)
		ft_putcharn_fd((params.flags[1] ? '0' : ' '), fill);
	ft_putchar_fd(c, 1);
	if (params.flags[0] || params.width < 0)
		ft_putcharn_fd((params.flags[1] ? '0' : ' '), fill);
	return (fill + 1);
}

unsigned int	putnbr(long int n, t_params params)
{
	char			*a;
	int				fill_z;
	int				fill_s;
	unsigned int	s;

	if (n == 0 && params.size == 0)
		a = ft_calloc(1, sizeof(char));
	else
		a = ft_itoa(abs_(n));
	fill_z = 0;
	fill_s = 0;
	if ((s = ft_strlen(a)) >= 0 && params.size > (int)s)
		fill_z = params.size - s;
	if (params.flags[1] && params.width > (int)s + (n < 0 ? 1 : 0)
			&& params.size < 0)
		fill_z = abs_(params.width) - s - (n < 0 ? 1 : 0);
	if (abs_(params.width) > fill_z + (int)s + (n < 0 ? 1 : 0))
		fill_s = abs_(params.width) - (fill_z + s + (n < 0 ? 1 : 0));
	ft_putcharn_fd(' ', ((!params.flags[0] && params.width >= 0) ? fill_s : 0));
	ft_putcharn_fd('-', (n < 0));
	ft_putcharn_fd('0', fill_z);
	ft_putstr_fd(a, 1);
	ft_putcharn_fd(' ', ((params.flags[0] || params.width < 0) ? fill_s : 0));
	free(a);
	return (s + fill_z + fill_s + (n < 0));
}

unsigned int	putunbr(long int n, t_params params)
{
	long int nb;

	nb = n;
	if (n < 0)
		nb = 4294967296 + n;
	return (putnbr(nb, params));
}

unsigned int	puthex(long int n, t_params params, int caps)
{
	char			*a;
	int				fill_z;
	int				fill_s;
	unsigned int	s;

	n = (n < 0 ? 4294967296 + n : n);
	a = ((n == 0 && params.size == 0) ? ft_calloc(1, sizeof(char)) :
			ft_itoa_hex(n, caps));
	s = ft_strlen(a);
	fill_z = 0;
	fill_s = 0;
	if (abs_(params.size) > (int)s && params.size > 0)
		fill_z = abs_(params.size) - s;
	if (params.flags[1] && params.width > params.size && params.size < 0)
		fill_z = abs_(params.width) - s;
	if (abs_(params.width) > fill_z + (int)s)
		fill_s = abs_(params.width) - (s + fill_z) - (n < 0);
	else
		fill_s = 0;
	ft_putcharn_fd(' ', ((!params.flags[0] && params.width >= 0) ? fill_s : 0));
	ft_putcharn_fd('0', fill_z);
	ft_putstr_fd(a, 1);
	ft_putcharn_fd(' ', ((params.flags[0] || params.width < 0) ? fill_s : 0));
	free(a);
	return (s + (fill_z > 0 ? fill_z : 0) + (fill_s > 0 ? fill_s : 0));
}
