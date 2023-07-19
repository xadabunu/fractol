/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:56:59 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/19 16:31:25 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_params(char **argv, t_mlx *s)
{
	// s->jx = ft_atod(argv[2]);
	// s->jy = ft_atod(argv[3]);
	// if (s->jx == -1)
	(void)argv; (void)s;
	return 1;
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
	const char	*j2 = "representing ...";

	if (argc == 1) return ;
	if (argc > 1 && argc < 4)
	{
		if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
		{
			if (argc == 2)
				return ;
			ft_putendl_fd((char *)m, 1);
			exit(1);
		}
		if (ft_strncmp(argv[1], "Julia", 6) == 0)
		{
			if (argc == 4 && get_params(argv, s) != -1)
				return ;
			ft_putendl_fd((char *)j1, 1);
			ft_putendl_fd((char *)j2, 1);
			exit(1);
		}
		print_all((char *)m, (char *)j1, (char *)j2);
	}
	else
		print_all((char *)m, (char *)j1, (char *)j2);
}
