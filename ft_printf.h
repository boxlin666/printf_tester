/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:01:09 by helin             #+#    #+#             */
/*   Updated: 2025/04/28 14:34:00 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putptr(void *ptr);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthex(unsigned int n, int isUpper);
int ft_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));

# endif