/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_types2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:52:30 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/12 15:22:26 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <printf.h>

unsigned int	putptr(void *ptr, t_params params)
{
	char			*a;
	unsigned int	s;
	int				fill_z;
	int				fill_s;

	a = ft_itoa_hex((unsigned long int)ptr, 0);
	a = ft_strjoin("0x", a);
	s = ft_strlen(a);
	if (params.size > (int)s)
		fill_z = params.size - s;
	else
		fill_z = 0;
	if (params.width > (int)s + fill_z)
		fill_s = params.width - (s + fill_z);
	else
		fill_s = 0;
	if (!params.flags[0])
		ft_putcharn_fd(' ', fill_s);
	ft_putcharn_fd('0', fill_z);
	ft_putstr_fd(a, 1);
	if (params.flags[0])
		ft_putcharn_fd(' ', fill_s);
	free(a);
	return (s + fill_z + fill_s);
}
