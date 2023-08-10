/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:57:44 by xadabunu          #+#    #+#             */
/*   Updated: 2023/08/10 14:55:22 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_type.h"

int	ft_isspace(const char c)
{
	return (c == '\n' || c == '\t' || c == '\v' || c == ' ' || c == '\r' \
	|| c == '\f');
}

static int	atoi_loop(const char *nptr, int sign, unsigned int i)
{
	long	tmp;
	long	res;

	res = 0;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		tmp = res;
		res = res * 10 + nptr[i] - '0';
		if (tmp > res)
			return (-1 * (sign == 1));
		++i;
	}
	return (sign * res);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	int				sign;

	if (!nptr)
		return (0);
	i = 0;
	while (ft_isspace(nptr[i]))
		++i;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	return (atoi_loop(nptr, sign, i));
}
