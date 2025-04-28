/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:07:12 by helin             #+#    #+#             */
/*   Updated: 2025/04/28 15:03:46 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putptr(void *ptr)
{
	unsigned long	n;
	int				count;
	char			hex[] = "0123456789abcdef";
	char			buf[sizeof(n) * 2];
	int				i;

	count = 0;
	i = 0;
	n = (unsigned long)ptr;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	while (n)
	{
		buf[i++] = hex[n % 16];
		n /= 16;
	}
	while (i--)
	{
		count += write(1, &buf[i], 1);
	}
	return (count);
}
