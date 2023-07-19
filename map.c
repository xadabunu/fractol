/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xadabunu <xadabunu@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:04:09 by xadabunu          #+#    #+#             */
/*   Updated: 2023/07/19 16:32:37 by xadabunu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_map(double val, double max, double new_min, double new_max)
{
	double	d;

	d = max / new_max - new_min;
	return (val / d + new_min);
}
