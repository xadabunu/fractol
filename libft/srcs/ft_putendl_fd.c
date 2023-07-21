/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:38:58 by xadabunu          #+#    #+#             */
/*   Updated: 2022/10/18 15:06:35 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

int	ft_putendl_fd(const char *s, int fd)
{
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	return (len + 1);
}
