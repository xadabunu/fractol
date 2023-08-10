/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:25:32 by xadabunu          #+#    #+#             */
/*   Updated: 2023/08/10 13:28:09 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		//printf("loop : %d\n", get_loop(x, y, s));
		printf("zoom : %f\n", s->zoom);
	}
	else
		printf("x : %d | y : %d | button: %d\n", x, y, button);
	return (0);
}
