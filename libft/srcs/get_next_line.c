/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:25:39 by xadabunu          #+#    #+#             */
/*   Updated: 2022/11/27 16:50:59 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	if (str[i] == '\n')
		++i;
	return (i);
}

static void	update_nl(char *nl)
{
	size_t	r;
	size_t	w;

	r = 0;
	while (nl[r] && nl[r] != '\n')
		++r;
	if (nl[r])
		++r;
	w = 0;
	while (nl[r])
		nl[w++] = nl[r++];
	while (nl[w])
		nl[w++] = '\0';
}

static char	*gnfree(char *dest)
{
	free(dest);
	return (NULL);
}

static char	*gnl_copy(char *src, long fd, char *buffer)
{
	char	*dest;
	size_t	len;
	long	ret;

	ret = 1;
	len = gnlen(src);
	dest = ft_calloc(sizeof(char), len + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, len);
	update_nl(src);
	while (dest[len - 1] != '\n' && ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret > 0)
		{
			ft_strlcpy(src, buffer, ret);
			dest = gnl_join(dest, src);
			update_nl(src);
			len = gnlen(dest);
		}
		else if (ret < 0)
			return (gnfree(dest));
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	nl[BUFFER_SIZE + 1] = "\0";
	char		buffer[BUFFER_SIZE];
	long		ret;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (nl[0] == '\0')
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 1)
			return (NULL);
		ft_strlcpy(nl, buffer, ret);
	}
	return (gnl_copy(nl, fd, buffer));
}
