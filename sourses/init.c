/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:19:26 by aenstein          #+#    #+#             */
/*   Updated: 2020/07/28 18:05:20 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	start_init(t_fractol *fractol)
{
	fractol->min.re = -2.0;
	fractol->max.re = 2.0;
	fractol->min.im = -2.0;
	fractol->max.im = fractol->min.im + (fractol->max.re - fractol->min.re) *
		HEIGHT / WIDTH;
	fractol->factor.re = (fractol->max.re - fractol->min.re) / (WIDTH - 1);
	fractol->factor.im = (fractol->max.im - fractol->min.im) / (HEIGHT - 1);
	fractol->k = init_complex(-0.4, 0.6);
	fractol->iter = 50;
}
