/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:12:02 by xadabunu          #+#    #+#             */
/*   Updated: 2023/08/09 18:29:20 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	julia_loop(int x, int y, t_mlx *s)
{
	double			a;
	double			squared_a;
	double			b;
	double			squared_b;
	unsigned int	loop;

	a = ft_map(x, WIDTH, s->x.start * s->zoom, s->x.end * s->zoom);
	b = ft_map(y, HEIGHT, s->y.start * s->zoom, s->y.end * s->zoom);
	loop = 0;
	while (loop < MAX_LOOP)
	{
		squared_a = a * a - b * b;
		squared_b = 2 * a * b;
		a = squared_a + s->j[0];
		b = squared_b + s->j[1];
		if (squared_a * squared_a + squared_b * squared_b > LIMIT_VALUE)
			return (s->get_color(loop));
		++loop;
	}
	return (BLACK);
}

int	julia(t_mlx *s)
{
	int	x;
	int	y;

	x = 0;
	create_image(s);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			color_pixel(&s->img, x, y, julia_loop(x, y, s));
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
	return (0);
}

static int	mandelbrot_loop(double x, double y, t_mlx *s)
{
	double			a;
	double			squared_a;
	double			b;
	double			squared_b;
	unsigned int	loop;

	x = ft_map(x, WIDTH, s->x.start * s->zoom, s->x.end * s->zoom);
	y = ft_map(y, HEIGHT, s->y.start * s->zoom, s->y.end * s->zoom);
	a = x;
	b = y;
	loop = 0;
	while (loop < MAX_LOOP)
	{
		squared_a = a * a - b * b;
		squared_b = 2 * a * b;
		a = squared_a + x;
		b = squared_b + y;
		if (fabs(squared_a * squared_a + squared_b * squared_b) > LIMIT_VALUE)
			return (s->get_color(loop));
		++loop;
	}
	return (BLACK);
}

int	mandelbrot(t_mlx *s)
{
	int	x;
	int	y;

	x = 0;
	create_image(s);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			color_pixel(&s->img, x, y, mandelbrot_loop(x, y, s));
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
	return (0);
}
