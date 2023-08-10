/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:59:08 by xadabunu          #+#    #+#             */
/*   Updated: 2023/08/10 14:59:37 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	refresh_image(t_mlx *s)
{
	mlx_clear_window(s->mlx, s->win);
	mlx_destroy_image(s->mlx, s->img.img);
	s->fun(s);
}

void	color_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->add + y * (img->line_size) + x * (img->bpp) / 8;
	*(unsigned int *)pixel = color;
}

void	create_image(t_mlx *s)
{
	s->img.img = mlx_new_image(s->mlx, WIDTH, HEIGHT);
	s->img.add = mlx_get_data_addr(s->img.img, &s->img.bpp, \
				&s->img.line_size, &s->img.end);
}
