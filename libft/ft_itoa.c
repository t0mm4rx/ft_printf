/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:36:59 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/04 09:43:27 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_n_in_ptr(char *ptr, long int n, int len)
{
	int i;

	if (n == 0 && len == 1)
	{
		ptr[0] = '0';
		return ;
	}
	if (n < 0)
	{
		ptr[0] = '-';
		ft_n_in_ptr(ptr, -n, len);
		return ;
	}
	i = len - 1;
	while (ptr[i])
		i--;
	ptr[i] = '0' + n % 10;
	if (n / 10)
		ft_n_in_ptr(ptr, n / 10, len);
}

static int	ft_get_number_length(long int n)
{
	int len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(long int n)
{
	char	*res;
	int		len;

	len = ft_get_number_length(n);
	res = ft_calloc(sizeof(char), len + 1);
	ft_n_in_ptr(res, n, len);
	return (res);
}
