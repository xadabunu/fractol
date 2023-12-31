/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:42:47 by xadabunu          #+#    #+#             */
/*   Updated: 2023/10/19 13:47:54 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include "libft/include/libft.h"
# include "minilibx/mlx.h"

# define WIDTH 500
# define HEIGHT 500
# define ZOOM 1.5
# define MAX_LOOP 200
# define LIMIT_VALUE 16

# define WHITE 0x00ffffff
# define BLACK 0x00000000
# define SCROLL_UP 4
# define SCROLL_DOWN 5

/* for MacOS */

# define ESCAPE_KEY 53
# define Q 12
# define ARROW_LEFT 123
# define ARROW_UP 126
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define R 15
# define G 5
# define B 11

/* for Linux */
/*
# define ESCAPE_KEY 65307
# define Q 113
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
*/

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_range
{
	float	start;
	float	end;
}	t_range;

typedef struct s_img
{
	void	*img;
	char	*add;
	int		bpp;
	int		line_size;
	int		end;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		(*loop)(double, double, struct s_mlx *);
	int		(*get_color)(int);
	float	zoom;
	t_range	x;
	t_range	y;
	float	j[2];
	t_img	img;
}	t_mlx;

typedef struct s_julia
{
	int	x;
	int	y;
}	t_julia;

double	ft_map(double val, double max, double new_min, double new_max);

void	command_line_management(int argc, char **argv, t_mlx *s);
void	set_mandelbrot(t_mlx *s);
void	set_julia(t_mlx *s);

int		show_fractal(t_mlx *s);
int		julia_loop(double x, double y, t_mlx *s);
int		mandelbrot_loop(double x, double y, t_mlx *s);

int		get_green(int loop);
int		get_red(int loop);
int		get_blue(int loop);

int		keyboard_manager(int key, t_mlx *s);
int		mouse_manager(int button, int x, int y, t_mlx *s);

void	create_image(t_mlx *s);
void	color_pixel(t_img *img, int x, int y, int color);
void	refresh_image(t_mlx *s);
void	color_pixel(t_img *img, int x, int y, int color);
void	create_image(t_mlx *s);

int		leave(t_mlx *s);

#endif