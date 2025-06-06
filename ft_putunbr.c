/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:08:17 by helin             #+#    #+#             */
/*   Updated: 2025/05/02 18:12:25 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putunbr(unsigned int n)
{
	char	buf[10];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n)
	{
		buf[i++] = '0' + (n % 10);
		n /= 10;
	}
	while (i--)
		count += write(1, &buf[i], 1);
	return (count);
}
