/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:42:47 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/18 17:08:30 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include "libft/libft.h"

# define WIDTH 500
# define HEIGHT 500
# define WHITE 16777215
# define ESCAPE_KEY 53

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

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*param;
}				t_mlx;

typedef struct s_inum
{
	int	a;
	int	b;
}		t_inum;

double	ft_map(double val, double max, double new_min, double new_max);

#endif