/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:18:34 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/21 12:33:50 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

int	ft_putchar_fd(const char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(const char *str, int fd)
{
	size_t	len;

	if (str == NULL)
		return (0);
	len = ft_strlen(str);
	write(fd, str, len);
	return (len);
}

int	ft_putunbr_fd(const unsigned int n, int fd)
{
	if (n > 9)
		ft_putunbr_fd(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
	return (ft_nbrlen(n));
}

static void	ft_subputnbr(const unsigned int n, int fd)
{
	if (n > 9)
		ft_subputnbr(n / 10, fd);
	ft_putchar_fd(48 + n % 10, fd);
}

int	ft_putnbr_fd(const int n, int fd)
{
	unsigned int	uns_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		uns_n = -n;
	}
	else
		uns_n = n;
	ft_subputnbr(uns_n, fd);
	return (ft_nbrlen(n));
}
