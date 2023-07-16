/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:42:47 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/16 16:44:22 by xadabunu         ###   ########.fr       */
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

#endif