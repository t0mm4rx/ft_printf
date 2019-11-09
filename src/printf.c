/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:17:36 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/09 12:16:31 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*ptr;
	int		count;

	ptr = (char *)format;
	count = 0;
	va_start(args, format);
	while (*ptr)
	{
		if (*ptr != '%' && ++count)
			ft_putchar_fd(*(ptr++), 1);
		else
		{
			if (count_stars(ptr) == 0)
				count += handle_format(&ptr, args);
			if (count_stars(ptr) == 1)
				count += handle_format_star(&ptr, va_arg(args, int), args);
			if (count_stars(ptr) == 2)
				count += handle_format_star2(&ptr, va_arg(args, int),
						va_arg(args, int), args);
		}
	}
	va_end(args);
	return (count);
}

int	handle_format(char **ptr, va_list args)
{
	char		type;
	t_params	params;

	(*ptr)++;
	get_flags(ptr, params.flags);
	params.width = get_width(ptr);
	params.size = get_size(ptr);
	type = **ptr;
	(*ptr)++;
	return (process(type, params, args));
}

int	handle_format_star(char **ptr, int arg, va_list args)
{
	char		type;
	t_params	params;

	(*ptr)++;
	get_flags(ptr, params.flags);
	if (**ptr == '*')
	{
		params.width = arg;
		(*ptr)++;
	}
	else
		params.width = get_width(ptr);
	if ((*ptr)[1] == '*')
	{
		params.size = arg;
		(*ptr) += 2;
	}
	else
		params.size = get_size(ptr);
	type = **ptr;
	(*ptr)++;
	return (process(type, params, args));
}

int	handle_format_star2(char **ptr, int arg1, int arg2, va_list args)
{
	t_params	params;
	char		type;

	(*ptr)++;
	get_flags(ptr, params.flags);
	(*ptr) += 3;
	type = **ptr;
	(*ptr)++;
	params.width = arg1;
	params.size = arg2;
	return (process(type, params, args));
}

int	process(char type, t_params params, va_list args)
{
	if (type == 'd' || type == 'i')
		return (putnbr(va_arg(args, int), params));
	if (type == 'u')
		return (putunbr(va_arg(args, int), params));
	if (type == 'x' || type == 'X')
		return (puthex(va_arg(args, int), params, (type == 'X')));
	if (type == 's')
		return (putstr(va_arg(args, char*), params));
	if (type == 'c')
		return (putchar_((char)va_arg(args, int), params));
	if (type == 'p')
		return (putptr(va_arg(args, void*), params));
	if (type == '%')
	{
		params.size = 1;
		return (putstr("%", params));
	}
	return (0);
}
