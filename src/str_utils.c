#include "printf.h"

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

int		ft_isdigit(const char c)
{
	return (c >= '0' && c <= '9');
}

int		ft_isincharset(const char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int		isflag(const char c)
{
	return (c == '-' || c == '0');
}
