/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:17:36 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/06 14:17:41 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*ptr;
	int		i;
	int		count;

	ptr = (char *)format;
	i = 0;
	count = 0;
	va_start(args, format);
	while (*ptr)
	{
		if (*ptr != '%')
		{
			ft_putchar_fd(*ptr, 1);
			ptr++;
			count++;
		}
		else
		{
			if (count_stars(ptr) == 0)
				count += handle_format(&ptr, args);
			if (count_stars(ptr) == 1)
				count += handle_format_star(&ptr, va_arg(args, int), args);
			if (count_stars(ptr) == 2)
				count += handle_format_star2(&ptr, va_arg(args, int), va_arg(args, int), args);
		}
	}
	va_end(args);
	return (count);
}

int	handle_format(char **ptr, va_list args)
{
	int		flags[2];
	int		width;
	int		size;
	char	type;

	(*ptr)++;
	get_flags(ptr, flags);
	width = get_width(ptr);
	size = get_size(ptr);
	type = **ptr;
	(*ptr)++;
	//printf(", w: %d, s: %d, f1: %d, f2: %d, t: %c\n", width, size, flags[0], flags[1], type);
	return process(type, flags, width, size, args);
}

int	handle_format_star(char **ptr, int arg, va_list args)
{
	int		flags[2];
	int		width;
	int		size;
	char	type;

	(*ptr)++;
	get_flags(ptr, flags);
	if (**ptr == '*')
	{
		width = arg;
		(*ptr)++;
	}
	else
		width = get_width(ptr);
	if ((*ptr)[1] == '*')
	{
		size = arg;
		(*ptr) += 2;
	}
	else
		size = get_size(ptr);
	type = **ptr;
	(*ptr)++;
	return process(type, flags, width, size, args);

}

int	handle_format_star2(char **ptr, int arg1, int arg2, va_list args)
{
	int		flags[2];
	char	type;

	(*ptr)++;
	get_flags(ptr, flags);
	(*ptr) += 3;
	type = **ptr;
	(*ptr)++;
	return process(type, flags, arg1, arg2, args);
}

int	process(char type, int flags[2], int width, int size, va_list args)
{
	if (type == 'd' || type == 'i')
		return (putnbr(va_arg(args, int), width, size, flags));
	if (type == 'u')
		return (putunbr(va_arg(args, int), width, size, flags));
	if (type == 'x' || type == 'X')
		return (puthex(va_arg(args, int), width, size, flags, (type == 'X')));
	if (type == 's')
		return (putstr(va_arg(args, char*), width, size, flags));
	if (type == 'c')
		return (putchar_((char)va_arg(args, int), width, size, flags));
	if (type == 'p')
		return (putptr(va_arg(args, void*), width, size, flags));
	if (type == '%')
		return (putstr("%", width, size, flags));
	return (0);
}
