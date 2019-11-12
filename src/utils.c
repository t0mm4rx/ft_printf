/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:51:47 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/12 16:07:14 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int			max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

long int	abs_(long int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void		fill_hex(int *fill_s, int *fill_z, int s, t_params params)
{
	*fill_z = 0;
	*fill_s = 0;
	if (abs_(params.size) > s && params.size > 0)
		*fill_z = abs_(params.size) - s;
	if (params.flags[1] && params.width > params.size && params.size < 0)
		*fill_z = abs_(params.width) - s;
	if (abs_(params.width) > *fill_z + (int)s)
		*fill_s = abs_(params.width) - (s + *fill_z);
	else
		*fill_s = 0;
	if (params.size < 0 && params.width < 0)
	{
		*fill_s = max(*fill_s, *fill_z);
		*fill_z = 0;
	}
}
