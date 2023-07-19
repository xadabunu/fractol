/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:29:52 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/19 18:16:17 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	command_line_management(int argc, char **argv, t_mlx *s);

#include <stdio.h>

int	get_color(int loop, double a, double b)
{
	double	d;
	int color;
	
	d = (loop / MAX_LOOP) * (a * a + b * b);
	color = ft_map(fabs(d), 1, BLACK, WHITE);
	return (color);
}

int	mandelbrot_loop(double x, double y)
{
	double			a;
	double			squared_a;
	double			b;
	double			squared_b;
	unsigned int	loop;

	x = ft_map(x, WIDTH, -ZOOM, ZOOM);
	y = ft_map(y, HEIGHT, -ZOOM, ZOOM);
	a = x;
	b = y;
	loop = 0;
	while (loop < MAX_LOOP)
	{
		squared_a = a * a - b * b;
		squared_b = 2 * a * b;
		a = squared_a + x;
		b = squared_b + y;
		if (fabs(squared_a * squared_a + squared_b * squared_b) > 16)
			return (get_color(loop, a, b));
		++loop;
	}
	return (get_color(loop, a, b));
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

int	leave(t_mlx *s)
{
	mlx_destroy_window(s->mlx, s->win);
	free(s->mlx);
	exit(0);
	return (0);
}

int	keyboard_manager(int key, t_mlx *s)
{
	if (key == ESCAPE_KEY || key == Q)
		leave(s);
	ft_putnbr_fd(key, 1);//line to remove
	return (0);
}

int	show_mouse(int button, int x, int y, t_mlx *s)
{
	(void)s;
	(void)button;
	printf("x : %d | y : %d\n", x, y);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	s;
	command_line_management(argc, argv, &s);
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, WIDTH, HEIGHT, "FRACT'OL");
	mandelbrot(&s);
	mlx_mouse_hook(s.win, show_mouse, &s);
	mlx_key_hook(s.win, keyboard_manager, &s);
	mlx_hook(s.win, ON_DESTROY, 0, leave, &s);
	mlx_loop(s.mlx);
	return (0);
}
