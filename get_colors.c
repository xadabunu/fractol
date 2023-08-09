/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:16:28 by xadabunu          #+#    #+#             */
/*   Updated: 2023/08/09 18:34:17 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_green(int loop)
{
	int r;
	int g;
	int bl;

	r = (int)(loop * sinf(loop)) % 256;
	g = (loop * loop) % 256;
	bl = (loop) % 256;
	
	return ((r << 16) + (g << 8) + bl);
}

int	get_blue(int loop)
{
	int r;
	int g;
	int bl;

	g = (int)(loop * sinf(loop)) % 256;
	bl = (loop * loop) % 256;
	r = (loop) % 256;
	
	return ((r << 16) + (g << 8) + bl);
}

int get_red(int loop)
{
	int r;
	int g;
	int bl;

	bl = (int)(loop * sinf(loop)) % 256;
	r = (loop * loop) % 256;
	g = (loop) % 256;
	
	return ((r << 16) + (g << 8) + bl);
}
