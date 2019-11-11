/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:59:59 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/11 12:55:56 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

static char		g_str[16] = "0123456789abcdef";
static char		g_str2[16] = "0123456789ABCDEF";

static void		ft_n_in_ptr_hex(char *ptr, unsigned long int n,
		int len, int caps)
{
	int		i;

	if (n == 0 && len == 1)
	{
		ptr[0] = '0';
		return ;
	}
	if (n < 0)
	{
		ptr[0] = '-';
		ft_n_in_ptr_hex(ptr, -n, len, caps);
		return ;
	}
	i = len - 1;
	while (ptr[i])
		i--;
	if (caps)
		ptr[i] = g_str2[n % 16];
	else
		ptr[i] = g_str[n % 16];
	if (n / 16)
		ft_n_in_ptr_hex(ptr, n / 16, len, caps);
}

static int		ft_get_number_length_hex(unsigned long int n)
{
	int len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char			*ft_itoa_hex(unsigned long int n, int caps)
{
	char	*res;
	int		len;

	len = ft_get_number_length_hex(n);
	res = ft_calloc(sizeof(char), len + 1);
	ft_n_in_ptr_hex(res, n, len, caps);
	return (res);
}
