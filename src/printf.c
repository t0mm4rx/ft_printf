/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:17:36 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/05 15:52:08 by tmarx            ###   ########.fr       */
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
		//printf("ptr: |%s|\n", ptr);
		if (*ptr != '%')
		{
			ft_putchar_fd(*ptr, 1);
			ptr++;
			count++;
		}
		else
		{
			if (count_stars(ptr) == 0)
				count += handle_format(&ptr);
			if (count_stars(ptr) == 0)
				count += handle_format_star(&ptr, va_arg(args, int));
			if (count_stars(ptr) == 0)
				count += handle_format_star2(&ptr, va_arg(args, int), va_arg(args, int));
		}
	}
	va_end(args);
	return (count);
}

int	handle_format(char **ptr)
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
	//printf("\n|%s|", *ptr);
	//printf(", w: %d, s: %d, f1: %d, f2: %d, t: %c\n", width, size, flags[0], flags[1], type);
	return (0);
}

int	handle_format_star(char **ptr, int arg)
{
	(void)arg;
	(*ptr)++;
	return (0);
}

int	handle_format_star2(char **ptr, int arg1, int arg2)
{
	(void)arg1;
	(void)arg2;
	(*ptr)++;
	return (0);
}

