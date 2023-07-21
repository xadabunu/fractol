/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:34:07 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/21 11:15:16 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

static int	ft_flags_manager(const char c, va_list *ap, unsigned int *ctr)
{
	if (c == '%')
		(*ctr) += ft_putchar_fd('%', STDOUT_FILENO);
	else if (c == 'c')
		(*ctr) += ft_putchar_fd(va_arg(*ap, int), STDOUT_FILENO);
	else if (c == 's')
		(*ctr) += ft_putstr_fd(va_arg(*ap, char *), STDOUT_FILENO);
	else if (c == 'd' || c == 'i')
		(*ctr) += ft_putnbr_fd(va_arg(*ap, int), STDOUT_FILENO);
	else if (c == 'p')
		(*ctr) += ft_putaddress_fd(va_arg(*ap, void *), STDOUT_FILENO);
	else if (c == 'x')
		(*ctr) += ft_puthexa_fd(va_arg(*ap, unsigned int), STDOUT_FILENO);
	else if (c == 'X')
		(*ctr) += ft_puthexa_upper_fd(va_arg(*ap, unsigned int), STDOUT_FILENO);
	else if (c == 'u')
		(*ctr) += ft_putunbr_fd(va_arg(*ap, unsigned int), STDOUT_FILENO);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	unsigned int	pos;
	unsigned int	ctr;

	va_start(ap, str);
	ctr = 0;
	while (*str)
	{
		pos = 0;
		while (str[pos] && str[pos] != '%')
			++pos;
		write(1, str, pos);
		ctr += pos;
		if (str[pos] == '%')
		{
			++pos;
			if (ft_flags_manager(str[pos], &ap, &ctr))
				++pos;
		}
		str += pos;
	}
	va_end(ap);
	return (ctr);
}
