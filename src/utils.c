/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:51:47 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/06 16:43:26 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int				max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

unsigned int	abs_(long int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
