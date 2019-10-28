/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:17:59 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/28 15:18:00 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_putchar(const char c)
{
	write(1, &c, 1);
}

int				ft_isdigit(const char c)
{
	return (c >= '0' && c <= '9');
}

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

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
