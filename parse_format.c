#include "ft_printf.h"

void	init_format(t_format *fmt)
{
	fmt->flag_hash = 0;
	fmt->flag_space = 0;
	fmt->flag_plus = 0;
	fmt->specifier = 0;
}

int	parse_format(const char *str, int start, t_format *fmt)
{
	int	i;

	i = start;
	init_format(fmt);
	while (str[i] == '#' || str[i] == ' ' || str[i] == '+')
	{
		if (str[i] == '#')
			fmt->flag_hash = 1;
		if (str[i] == ' ')
			fmt->flag_space = 1;
		if (str[i] == '+')
			fmt->flag_plus = 1;
		i++;
	}
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
		|| str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X'
		|| str[i] == '%')
	{
		fmt->specifier = str[i];
		i++;
	}
	else
		fmt->specifier = 0;
	return (i - start);
}
