/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_types2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:52:30 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/04 10:57:59 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <printf.h>

unsigned int	putptr(void *ptr, unsigned int width, unsigned int size,
		int flags[2])
{
	ft_putstr_fd("0x", 1);
	return (puthex((unsigned long int)ptr, width, size, flags, 0) + 2);
}
