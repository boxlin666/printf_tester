/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helin <helin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:07:41 by helin             #+#    #+#             */
/*   Updated: 2025/04/28 15:19:37 by helin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_putnbr_rec(unsigned int n)
{
	char	c;
	int		count = 0;

	if (n >= 10)
		count += ft_putnbr_rec(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
	return (count + 1);
}

int	ft_putnbr(int n)
{
	int	count = 0;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	count += ft_putnbr_rec((unsigned int)n);
	return (count);
}
