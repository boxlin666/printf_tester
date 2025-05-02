/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:57:09 by helin             #+#    #+#             */
/*   Updated: 2025/05/02 15:42:44 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int handle_conversion(t_format *spec, va_list args)
{
	const char	*warning = "Warning: spurious trailing '%%' in format\n";

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
		return (ft_puthex(va_arg(args, unsigned int), 0, spec));
	else if (spec->specifier == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1, spec));
	else if (spec->specifier == '%')
		return (ft_putchar('%'));
	write(2, warning, 41);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_format	spec;
	int		total_len = 0;
	int		index = 0;  // 新增索引变量

	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;  // 跳过'%'
			int next_index = parse_format(format, index, &spec);  // 传递index作为start
			total_len += handle_conversion(&spec, args);  // 处理并添加长度
			index = next_index;  // 更新index
		}
		else
		{
			write(1, &format[index], 1);  // 输出普通字符
			total_len++;  // 增加长度
			index++;  // 移动到下一个
		}
	}
	va_end(args);
	return (total_len);
}
