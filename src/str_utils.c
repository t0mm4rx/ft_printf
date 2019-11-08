/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:17:59 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/08 17:45:12 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int				ft_isincharset(const char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int				isflag(const char c)
{
	return (c == '-' || c == '0');
}

int				is_type(const char c)
{
	return (c == 'i' || c == 'd' || c == 'p' || c == '%'
			|| c == 'x' || c == 'X' || c == 's' || c == 'u' || c == 'c');
}

void			ft_putcharn_fd(char c, int n)
{
	while (n--)
		ft_putchar_fd(c, 1);
}
