/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:29:52 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/31 12:00:04 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	command_line_management(int argc, char **argv, t_mlx *s);

#include <stdio.h>

static int	in_window(int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (x > WIDTH || y > HEIGHT)
		return (0);
	return (1);
}

void	color_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;
	
	if (in_window(x, y) == 0)
		return ;
	pixel = img->add + y * (img->size) + x * (img->bits) / 8;
	*(unsigned int *)pixel = color;
}

void	create_image(t_mlx *s)
{
	s->img.img = mlx_new_image(s->mlx, WIDTH, HEIGHT);
	s->img.add = mlx_get_data_addr(s->img.img, &s->img.bits, \
				&s->img.size, &s->img.end);
}

int	leave(t_mlx *s)
{
	mlx_destroy_image(s->mlx, s->img.img);
	mlx_destroy_window(s->mlx, s->win);
	free(s->mlx);
	exit(0);
	return (0);
}

int	keyboard_manager(int key, t_mlx *s)
{
	if (key == ESCAPE_KEY || key == Q)
		leave(s);
	if (key == ARROW_LEFT)
	{
		s->x_start -= 0.05;
		s->x_end -= 0.05;
	}
	if (key == ARROW_UP)
	{
		s->y_start -= 0.05;
		s->y_end -= 0.05;
	}
	if (key == ARROW_RIGHT)
	{
		s->x_start += 0.05;
		s->x_end += 0.05;
	}
	if (key == ARROW_DOWN)
	{
		s->y_start += 0.05;
		s->y_end += 0.05;
	}
	mlx_destroy_image(s->mlx, s->img.img);
	s->fun(s);
	//ft_putnbr_fd(key, 1);//line to remove
	return (0);
}

int	mouse_manager(int button, int x, int y, t_mlx *s)
{
	if (button == SCROLL_UP)
	{
		s->zoom /= 1.1;
		mlx_destroy_image(s->mlx, s->img.img);
		s->fun(s);
	}
	else if (button == SCROLL_DOWN)
	{
		s->zoom *= 1.1;
		mlx_destroy_image(s->mlx, s->img.img);
		s->fun(s);
	}
	else
		printf("x : %d | y : %d | button: %d\n", x, y, button);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	s;
	command_line_management(argc, argv, &s);
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, WIDTH, HEIGHT, "FRACT'OL");
	s.fun(&s);
	mlx_mouse_hook(s.win, mouse_manager, &s);
	mlx_key_hook(s.win, keyboard_manager, &s);
	mlx_hook(s.win, ON_DESTROY, 0, leave, &s);
	mlx_loop(s.mlx);
	return (0);
}
