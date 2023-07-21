/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:56:59 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/21 19:10:40 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_mandelbrot(t_mlx *s);
void	set_julia(t_mlx *s);

static void	set_params(t_mlx *s, float x, float y)
{
	s->j[0] = x;
	s->j[1] = y;
}

static int	get_params(char *set, t_mlx *s)
{
	if (ft_strncmp(set, "1", 2) == 0)
		set_params(s, 0.3, -0.5);
	else if (ft_strncmp(set, "2", 2) == 0)
		set_params(s, 0.285, -0.01);
	else if (ft_strncmp(set, "3", 2) == 0)
		set_params(s, -0.038088, -0.9754633);
	else if (ft_strncmp(set, "4", 2) == 0)
		set_params(s, -1.417022285618, -0.0099534);
	else if (ft_strncmp(set, "5", 2) == 0)
		set_params(s, -1.476, 0);
	else if (ft_strncmp(set, "6", 2) == 0)
		set_params(s, -0.4, -0.6);
	else if (ft_strncmp(set, "7", 2) == 0)
		set_params(s, -0.8, -0.156);
	else
		return (1);
	return (0);
}

static void	print_all(char *m, char *j1, char *j2)
{
	ft_putendl_fd(m, 1);
	ft_putendl_fd(j1, 1);
	ft_putendl_fd(j2, 1);
	exit(1);
}

void	command_line_management(int argc, char **argv, t_mlx *s)
{
	const char	*m = "For Mandelbrot set use \"./fractol Mandelbrot\".";
	const char	*j1 = "For Julia set use \"./fractol Julia <n>\" with <n>";
	const char	*j2 = "representing which Julia set to display (1-7).";

	if (argc == 1) return (set_mandelbrot(s));
	if (argc > 1 && argc < 4)
	{
		if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
		{
			if (argc == 2)
				return (set_mandelbrot(s));
			ft_putendl_fd((char *)m, 1);
			exit(1);
		}
		if (ft_strncmp(argv[1], "Julia", 6) == 0)
		{
			if (argc == 3 && get_params(argv[2], s) != 1)
				return (set_julia(s));
			ft_putendl_fd((char *)j1, 1);
			ft_putendl_fd((char *)j2, 1);
			exit(1);
		}
		print_all((char *)m, (char *)j1, (char *)j2);
	}
	else
		print_all((char *)m, (char *)j1, (char *)j2);
}
