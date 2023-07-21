/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:42:43 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/21 11:15:22 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

static unsigned int	ft_hexalen(unsigned long long n)
{
	unsigned int	ctr;

	ctr = 1;
	while (n > 15)
	{
		++ctr;
		n /= 16;
	}
	return (ctr);
}

static void	ft_recur(const unsigned long long n, const char *base, int fd)
{
	if (n > 15)
		ft_recur(n / 16, base, fd);
	ft_putchar_fd(base[n % 16], fd);
}

int	ft_puthexa_fd(const size_t n, int fd)
{
	ft_recur(n, "0123456789abcdef", fd);
	return (ft_hexalen(n));
}

int	ft_puthexa_upper_fd(const unsigned int n, int fd)
{
	ft_recur(n, "0123456789ABCDEF", fd);
	return (ft_hexalen(n));
}

int	ft_putaddress_fd(const void *ptr, int fd)
{
	return (ft_putstr_fd("0x", fd) + \
				ft_puthexa_fd((unsigned long long)ptr, fd));
}
