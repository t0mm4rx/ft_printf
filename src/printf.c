#include "printf.h"

int		ft_printf(const char *format, ...)
{
	char			*ptr;
	unsigned int	char_printed;

	ptr = (char *)format;
	char_printed = 0;
	if (!ptr)
		return (0);
	while (*ptr)
	{
		if (*ptr != '%')
		{
			char_printed++;
			ft_putchar(*(ptr++));
		}
		else
			process_format(&ptr, &char_printed);
	}
	return (char_printed);
}

void	process_format(char **ptr, unsigned int *char_printed)
{
	int		width;
	int		size;
	char	type;

	width = -1;
	size = -1;
	(void)char_printed;
	*ptr = *ptr + 1;
	while (isflag(**ptr))
		*ptr = *ptr + 1;
	if (ft_isdigit(**ptr))
		width = ft_atoi(*ptr);
	while (ft_isdigit(**ptr))
		*ptr = *ptr + 1;
	if (**ptr == '.')
	{
		*ptr = *ptr + 1;
		size = ft_atoi(*ptr);
		while (ft_isdigit(**ptr))
			*ptr = *ptr + 1;
	}
	type = **ptr;
	*ptr = *ptr + 1;
	printf("Width: %d\n", width);
	printf("Size: %d\n", size);
	printf("Type: %c\n", type);
}
