/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:29:52 by xadabunu          #+#    #+#             */
/*   Updated: 2023/08/09 18:37:52 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	command_line_management(int argc, char **argv, t_mlx *s);

#include <stdio.h>

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



int get_loop(int x, int y, t_mlx *s) {
	
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
			return (loop);
		++loop;
	}
	return (loop);

	
}



int	leave(t_mlx *s)
{
	mlx_destroy_image(s->mlx, s->img.img);
	mlx_destroy_window(s->mlx, s->win);
	free(s->mlx);
	exit(0);
	return (0);
}

void	arrow_manager(int key, t_mlx *s)
{
	if (key == ARROW_LEFT)
	{
		s->x.start -= 0.05;
		s->x.end -= 0.05;
		refresh_image(s);
	}
	else if (key == ARROW_UP)
	{
		s->y.start -= 0.05;
		s->y.end -= 0.05;
		refresh_image(s);
	}
	else if (key == ARROW_RIGHT)
	{
		s->x.start += 0.05;
		s->x.end += 0.05;
		refresh_image(s);
	}
	else if (key == ARROW_DOWN)
	{
		s->y.start += 0.05;
		s->y.end += 0.05;
		refresh_image(s);
	}
}

void	color_manager(int key, t_mlx *s)
{
	if (key == R)
	{
		s->get_color = get_red;
		refresh_image(s);
	}
	else if (key == G)
	{
		s->get_color = get_green;
		refresh_image(s);
	}
	else if (key == B)
	{
		s->get_color = get_blue;
		refresh_image(s);
	}
}

int	keyboard_manager(int key, t_mlx *s)
{
	if (key == ESCAPE_KEY || key == Q)
		leave(s);
	arrow_manager(key, s);
	color_manager(key, s);
	//printf("key : %d\n", key);//line to remove
	return (0);
}

int	mouse_manager(int button, int x, int y, t_mlx *s)
{
	if (button == SCROLL_UP)
	{
		s->zoom *= 0.9;
		refresh_image(s);
	}
	else if (button == SCROLL_DOWN)
	{
		s->zoom *= 1.1;
		refresh_image(s);
	}
	else if (button == 1)
	{
		printf("loop : %d\n", get_loop(x, y, s));
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
