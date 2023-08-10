/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:32:09 by xadabunu          #+#    #+#             */
/*   Updated: 2023/08/10 14:50:19 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

size_t	ft_nbrlen(long n)
{
	unsigned int	ctr;

	ctr = 1;
	if (n < 0)
	{
		++ctr;
		n = -n;
	}
	while (n > 9)
	{
		++ctr;
		n /= 10;
	}
	return (ctr);
}
