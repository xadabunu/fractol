/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:42:47 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/20 17:54:36 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# define WIDTH 500
# define HEIGHT 500
# define ZOOM 1.5
# define MAX_LOOP 300

# define WHITE 0x00ffffff
# define BLACK 0x00000000

# define ESCAPE_KEY 53
# define Q 12

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

typedef struct s_img
{
	void	*img;
	char	*add;
	int		bits;
	int		size;
	int		end;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		(*fun)();
	t_img	img;
}	t_mlx;

typedef struct s_inum
{
	int	a;
	int	b;
}		t_inum;

double	ft_map(double val, double max, double new_min, double new_max);

#endif