/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:29:52 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/15 23:46:00 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	command_line_management(int argc, char **argv)
{
	(void)argc;
	(void)argv;
}

int	main(int argc, char *argv[])
{
	void    *mlx;
	void    *window;

	command_line_management(argc, argv);
	mlx = mlx_init();
	window = mlx_new_window(mlx, WIDTH, HEIGHT, "FRACT'OL");
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
	mlx_destroy_display(mlx);
	free(mlx);    
}
