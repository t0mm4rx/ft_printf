/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_types2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:52:30 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/04 13:10:39 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <printf.h>

unsigned int	putptr(void *ptr, unsigned int width, unsigned int size,
		int flags[2])
{
	char			*a;
	unsigned int	s;
	int				fill_z;
	int				fill_s;
	int				i;

	a = ft_itoa_hex((unsigned long int)ptr, 0);
	a = ft_strjoin("0x", a);
	s = ft_strlen(a);
	if (size > s)
		fill_z = size - s;
	else
		fill_z = 0;
	if (width > s + fill_z)
		fill_s = width - (s + fill_z);
	else
		fill_s = 0;
	i = 0;
	while (!flags[0] && i++ < fill_s)
		ft_putchar_fd(' ', 1);
	i = 0;
	while (i++ < fill_z)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(a, 1);
	i = 0;
	while (flags[0] && i++ < fill_s)
		ft_putchar_fd(' ', 1);
	free(a);
	return (s + fill_z + fill_s);
}
