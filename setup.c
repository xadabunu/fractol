/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:17:37 by xadabunu          #+#    #+#             */
/*   Updated: 2023/09/19 22:19:08 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_mandelbrot(t_mlx *s)
{
	s->zoom = 1.0;
	s->x.start = -2.0;
	s->x.end = 1.0;
	s->y.start = -1.5;
	s->y.end = 1.5;
	s->loop = mandelbrot_loop;
	s->get_color = get_green;
}

void	set_julia(t_mlx *s)
{
	s->zoom = 1.0;
	s->x.start = -1.5;
	s->x.end = 1.5;
	s->y.start = -1.5;
	s->y.end = 1.5;
	s->loop = julia_loop;
	s->get_color = get_green;
}

int	leave(t_mlx *s)
{
	mlx_destroy_image(s->mlx, s->img.img);
	mlx_destroy_window(s->mlx, s->win);
	free(s->mlx);
	exit(0);
	return (0);
}
