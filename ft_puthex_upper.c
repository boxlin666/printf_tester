/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:16:16 by helin             #+#    #+#             */
/*   Updated: 2025/05/02 18:18:09 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_puthex_upper(unsigned int n, t_format *spec)
{
	char	*hex;
	char	buf[8];
	int		i;
	int		count;

	i = 0;
	count = 0;
	hex = "0123456789ABCDEF";
	if (n == 0)
		return (write(1, "0", 1));
	if (spec->flag_hash)
		count += write(1, "0X", 2);
	while (n)
	{
		buf[i++] = hex[n % 16];
		n /= 16;
	}
	while (i--)
		count += write(1, &buf[i], 1);
	return (count);
}
