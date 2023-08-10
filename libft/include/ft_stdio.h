/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:22:53 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/07 11:22:53 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <sys/types.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);

int		ft_putchar_fd(const char c, int fd);
int		ft_putstr_fd(const char *s, int fd);
int		ft_putendl_fd(const char *s, int fd);
int		ft_putnbr_fd(const int n, int fd);
int		ft_putunbr_fd(const unsigned int n, int fd);
int		ft_puthexa_fd(const size_t n, int fd);
int		ft_puthexa_upper_fd(const unsigned int n, int fd);
int		ft_putaddress_fd(const void *ptr, int fd);

size_t	ft_strlen(const char *str);
size_t	ft_nbrlen(const long n);

#endif