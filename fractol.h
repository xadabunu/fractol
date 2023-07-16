/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:42:47 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/15 00:50:49 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "minilibx-linux/mlx.h"
# include <stdlib.h>

# define WIDTH 500
# define HEIGHT 500

typedef struct	s_mlx
{
    void	*mlx;
	void	*window;
	void	*param;
}				t_mlx;

#endif