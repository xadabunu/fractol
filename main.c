/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:29:52 by xadabunu          #+#    #+#             */
/*   Updated: 2023/08/10 16:22:27 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	command_line_management(int argc, char **argv, t_mlx *s);

int	leave(t_mlx *s)
{
	mlx_destroy_image(s->mlx, s->img.img);
	mlx_destroy_window(s->mlx, s->win);
	free(s->mlx);
	exit(0);
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
