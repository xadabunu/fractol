/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:12:02 by xadabunu          #+#    #+#             */
/*   Updated: 2023/09/19 18:41:38 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_loop(double x, double y, t_mlx *s)
{
	double			a;
	double			b;
	double			temp;
	unsigned int	loop;

	a = ft_map(x, WIDTH, s->x.start * s->zoom, s->x.end * s->zoom);
	b = ft_map(y, HEIGHT, s->y.start * s->zoom, s->y.end * s->zoom);
	loop = 0;
	while (loop < MAX_LOOP)
	{
		temp = a * a - b * b;
		b = 2 * a * b + s->j[1];
		a = temp + s->j[0];
		if (a * a + b * b > LIMIT_VALUE)
			return (s->get_color(loop));
		++loop;
	}
	return (BLACK);
}

int	mandelbrot_loop(double x, double y, t_mlx *s)
{
	double			a;
	double			b;
	double			temp;
	unsigned int	loop;

	x = ft_map(x, WIDTH, s->x.start * s->zoom, s->x.end * s->zoom);
	y = ft_map(y, HEIGHT, s->y.start * s->zoom, s->y.end * s->zoom);
	a = x;
	b = y;
	loop = 0;
	while (loop < MAX_LOOP)
	{
		temp = a * a - b * b;
		b = 2 * a * b + y;
		a = temp + x;
		if (fabs(a * a + b * b) > LIMIT_VALUE)
			return (s->get_color(loop));
		++loop;
	}
	return (BLACK);
}

int	show_fractal(t_mlx *s)
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
			color_pixel(&s->img, x, y, s->loop(x, y, s));
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
	return (0);
}
