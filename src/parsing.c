/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:18:12 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/05 11:58:37 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		count_stars(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] && !is_type(str[i]))
		count += (str[i++] == '*');
	return (count);
}

void	get_flags(char **ptr, int flags[2])
{
	flags[0] = 0;
	flags[1] = 0;
	while (isflag(**ptr))
	{
		if (**ptr == '-')
			flags[0] = 1;
		if (**ptr == '0')
			flags[1] = 1;
		(*ptr)++;
	}
}

int		get_width(char **ptr)
{
	int w;

	if (!ft_isdigit(**ptr))
		return (-1);
	w = ft_atoi(*ptr);
	while (ft_isdigit(**ptr))
		(*ptr)++;
	return (w);
}

int		get_size(char **ptr)
{
	int s;

	if (**ptr == '.')
	{
		(*ptr)++;
		s = ft_atoi(*ptr);
		while (ft_isdigit(**ptr))
			(*ptr)++;
		return (s);
	}
	else
		return (-1);
}
