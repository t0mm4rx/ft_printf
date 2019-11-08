/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_types2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:52:30 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/08 17:49:42 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <printf.h>

unsigned int	putptr(void *ptr, unsigned int width, int size,
		int flags[2])
{
	char			*a;
	unsigned int	s;
	int				fill_z;
	int				fill_s;

	a = ft_itoa_hex((unsigned long int)ptr, 0);
	a = ft_strjoin("0x", a);
	s = ft_strlen(a);
	if (size > (int)s)
		fill_z = size - s;
	else
		fill_z = 0;
	if (width > s + fill_z)
		fill_s = width - (s + fill_z);
	else
		fill_s = 0;
	if (!flags[0])
		ft_putcharn_fd(' ', fill_s);
	ft_putcharn_fd('0', fill_z);
	ft_putstr_fd(a, 1);
	if (flags[0])
		ft_putcharn_fd(' ', fill_s);
	free(a);
	return (s + fill_z + fill_s);
}
