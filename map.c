/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:04:09 by xadabunu          #+#    #+#             */
/*   Updated: 2023/09/19 22:18:13 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_map(double val, double max, double new_min, double new_max)
{
	double	d;
	double	range;

	d = val / max;
	range = fabs(new_max - new_min);
	d = new_min + range * d;
	return (d);
}
