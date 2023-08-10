/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:04:09 by xadabunu          #+#    #+#             */
/*   Updated: 2023/08/10 15:16:45 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_map(double val, double max, double new_min, double new_max)
{
	double	d;
	double	range;

	d = val / max;
	range = fabs(new_max - new_min);
	d = new_min + range * d;
	return (d);
}

void	set_mandelbrot(t_mlx *s)
{
	s->zoom = 1.0;
	s->x.start = -2.0;
	s->x.end = 1.0;
	s->y.start = -1.5;
	s->y.end = 1.5;
	s->fun = mandelbrot;
	s->get_color = get_green;
}

void	set_julia(t_mlx *s)
{
	s->zoom = 1.0;
	s->x.start = -1.5;
	s->x.end = 1.5;
	s->y.start = -1.5;
	s->y.end = 1.5;
	s->fun = julia;
	s->get_color = get_green;
}
