/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:01:09 by helin             #+#    #+#             */
/*   Updated: 2025/05/02 15:26:13 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_format
{
	int		flag_hash;
	int		flag_space;
	int		flag_plus;
	char	specifier;
}			t_format;

int			ft_putchar(char c);
int			ft_putstr(char *s);
int			ft_putptr(void *ptr);
int			ft_putnbr(int n, t_format *spec);
int			ft_putunbr(unsigned int n);
int			ft_puthex(unsigned int n, int isUpper, t_format *spec);
int			ft_printf(const char *format, ...) __attribute__((format(printf, 1,
						2)));

int	parse_format(const char *str, int start, t_format *fmt);
#endif