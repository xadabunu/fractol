/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:58:17 by xadabunu          #+#    #+#             */
/*   Updated: 2022/09/23 10:58:27 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ss;

	if (!s)
		return ;
	ss = (char *)s;
	i = 0;
	while (i < n)
		ss[i++] = 0;
}
