/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:29:52 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/16 20:00:19 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_all(char *m, char *f1, char *f2)
{
	ft_putendl_fd(m, 1);
	ft_putendl_fd(f1, 1);
	ft_putendl_fd(f2, 1);
	exit(1);
}

void	command_line_management(int argc, char **argv)
{
	const char	*m = "For Mandelbrot set use \"./fractol Mandelbrot\".";
	const char	*f1 = "For Julia set use \"./fractol Julia <n>\" with <n>";
	const char	*f2 = "representing ...";

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
			if (argc == 3 && ft_atoi(argv[2]) != -1)
				return ;
			ft_putendl_fd((char *)f1, 1);
			ft_putendl_fd((char *)f2, 1);
			exit(1);
		}
		print_all((char *)m, (char *)f1, (char *)f2);
	}
	else
		print_all((char *)m, (char *)f1, (char *)f2);
}

#include <stdio.h>

int	get_color(int loop, double a, double b)
{
	double	d;

	printf("loop: %d\n", loop);	
	d = log2(log2((a * a + b * b) / 2));
	return ((int)sqrt(loop - d) % 16777216);
}

int	mandelbrot_loop(double x, double y)
{
	double	a;
	double	squared_a;
	double	b;
	double	squared_b;
	int	loop;

	a = x;
	b = y;
	loop = 0;
	while (loop < 100)
	{
		squared_a = a * a - b * b;
		squared_b = 2 * a * b;
		b = squared_b + y;
		a = squared_a + x;
		printf("[%f]\n", fabs(squared_a + squared_b));
		if (fabs(squared_a + squared_b) > 16)
			return (get_color(loop, a, b));
		++loop;
	}
	return (WHITE);
}

int	show_key(int key, void *param)
{
	(void)param;
	ft_putnbr_fd(key, 1);
	return (0);
}

int show_mouse(int button, int x, int y, void *param)
{
	(void)param;
	printf("button : %d | x : %d | y : %d\n", button, x, y);
	return (0);
}

void	mandelbrot(t_mlx *s)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_pixel_put(s->mlx, s->win, x, y, mandelbrot_loop(x, y));
			++y;
		}
		++x;
	}
}

// 53 -> ESC

int	main(int argc, char *argv[])
{
	t_mlx	s;
	(void)argc;
	(void)argv;
	//command_line_management(argc, argv);
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, WIDTH, HEIGHT, "FRACT'OL");
	mandelbrot(&s);
	mlx_key_hook(s.win, show_key, (void *)0);
	mlx_mouse_hook(s.win, show_mouse, (void *)0);
	mlx_loop(s.mlx);
	//mlx_destroy_window(mlx.mlx_ptr, mlx.window_ptr);
	//mlx_destroy_display(mlx);
	free(s.mlx);
	return (0);
}
