/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:57:09 by helin             #+#    #+#             */
/*   Updated: 2025/05/02 18:19:45 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_print_arg(va_list args, t_format *spec)
{
	if (spec->specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (spec->specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (spec->specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (spec->specifier == 'd' || spec->specifier == 'i')
		return (ft_putnbr(va_arg(args, int), spec));
	else if (spec->specifier == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (spec->specifier == 'x')
		return (ft_puthex(va_arg(args, unsigned int), spec));
	else if (spec->specifier == 'X')
		return (ft_puthex_upper(va_arg(args, unsigned int), spec));
	else if (spec->specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

void	init_format(t_format *spec)
{
	spec->flag_hash = 0;
	spec->flag_plus = 0;
	spec->flag_space = 0;
	spec->specifier = ' ';
}

static int	parse_format(const char **format_ptr, t_format *spec)
{
	const char	*format = *format_ptr;

	while (*format == '#' || *format == ' ' || *format == '+')
	{
		if (*format == '#')
			spec->flag_hash = 1;
		if (*format == ' ')
			spec->flag_space = 1;
		if (*format == '+')
			spec->flag_plus = 1;
		format++;
	}
	if (*format == 'c' || *format == 's' || *format == 'p' || *format == 'd'
		|| *format == 'i' || *format == 'u' || *format == 'x' || *format == 'X'
		|| *format == '%')
	{
		spec->specifier = *format;
		*format_ptr = format;
	}
	else
	{
		return (-1);
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_format	spec;
	int			total_len;

	init_format(&spec);
	total_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (parse_format(&format, &spec) == -1)
				return (-1);
			total_len += ft_print_arg(args, &spec);
		}
		else
			total_len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (total_len);
}
