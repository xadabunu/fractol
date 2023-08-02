#include "fractol.h"

static int	get_color(int loop, double a, double b)
{
	double	d;
	int color;

	(void)a;
	(void)b;
	
	int r = (int)(loop * sinf(loop)) % 256;
	int g = (loop * loop) % 256;
	int bl = (loop) % 256;

	if (r && !g && !bl) return (BLACK);
	
	return ((r << 16) + (g << 8) + bl) ;
	
	d = (loop / MAX_LOOP) * (a * a + b * b);
	color = ft_map(fabs(d), 1, BLACK, WHITE);
	return (color);
}

static int	julia_loop(int x, int y, t_mlx *s)
{
	double			a;
	double			squared_a;
	double			b;
	double			squared_b;
	unsigned int	loop;

	a = ft_map(x, WIDTH, s->x_start * s->zoom, s->x_end * s->zoom);
	b = ft_map(y, HEIGHT, s->y_start * s->zoom, s->y_end * s->zoom);
	loop = 0;
	while (loop < MAX_LOOP)
	{
		squared_a = a * a - b * b;
		squared_b = 2 * a * b;
		a = squared_a + s->j[0];
		b = squared_b + s->j[1];
		if (squared_a * squared_a + squared_b * squared_b > 16)
			return (get_color(loop, a, b));
		++loop;
	}
	return (get_color(loop, a, b));
}

int	julia(t_mlx *s)
{
	int	x;
	int	y;

	x = 0;
	create_image(s);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			color_pixel(&s->img, x, y, julia_loop(x, y, s));
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
	return (0);
}

static int	mandelbrot_loop(double x, double y, t_mlx *s)
{
	double			a;
	double			squared_a;
	double			b;
	double			squared_b;
	unsigned int	loop;

	x = ft_map(x, WIDTH, s->x_start * s->zoom, s->x_end * s->zoom);
	y = ft_map(y, HEIGHT, s->y_start * s->zoom, s->y_end * s->zoom);
	a = x;
	b = y;
	loop = 0;
	while (loop < MAX_LOOP)
	{
		squared_a = a * a - b * b;
		squared_b = 2 * a * b;
		a = squared_a + x;
		b = squared_b + y;
		if (fabs(squared_a * squared_a + squared_b * squared_b) > 8)
			return (get_color(loop, a, b));
		++loop;
	}
	return (get_color(loop, a, b));
}

int	mandelbrot(t_mlx *s)
{
	int	x;
	int	y;

	x = 0;
	create_image(s);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			color_pixel(&s->img, x, y, mandelbrot_loop(x, y, s));
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img.img, 0, 0);
	return (0);
}
