/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:04:09 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/20 16:39:40 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

double	ft_map(double val, double max, double new_min, double new_max)
{
	double	d;
	double	range;

	d = val / max;
	range = new_max - new_min;
	d = new_min + range * d;
	return (d);
}
