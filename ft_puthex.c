/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:08:27 by helin             #+#    #+#             */
/*   Updated: 2025/04/25 14:59:34 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_puthex(unsigned int n, int isUpper)
{
	char	*hex;
	char	buf[8];
	int i;
	int count;
	
	if (isUpper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	i = 0, count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n)
	{
		buf[i++] = hex[n % 16];
		n /= 16;
	}
	while (i--)
		count += write(1, &buf[i], 1);
	return (count);
}
