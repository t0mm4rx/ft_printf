/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:17:59 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/05 09:13:33 by tmarx            ###   ########.fr       */
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
	return(c == 'i' || c == 'd' || c == 'p' || c == '%'
			|| c == 'x' || c == 'X' || c == 's' || c == 'u' || c == 'c');
}

void			replace_first_star(char **src, int n)
{
	char	*a;
	int		i;
	int		j;
	int		l;
	char	*res;

	a = ft_itoa(n);
	l = ft_strlen(*src) - 1 + ft_strlen(a);
	if (!(res = ft_calloc(l + 1, sizeof(char))))
			return ;
	i = 0;
	j = 0;
	while ((*src)[i] != '*' && (*src)[i])
	{
		res[i] = (*src)[i];
		i++;
	}
	l = i + 1;
	while (a[j])
		res[i++] = a[j++];
	while ((*src)[l])
		res[i++] = (*src)[l++];
	free(*src);
	*src = res;
}
