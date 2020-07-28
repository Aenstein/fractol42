/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 13:58:17 by aenstein          #+#    #+#             */
/*   Updated: 2020/07/26 16:54:57 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move(int key, t_fractol *fractol)
{
	t_complex	delta;

	delta = init_complex(fabs(fractol->max.re - fractol->min.re),
		fabs(fractol->max.im - fractol->min.im));
	if (key == 2)
	{
		fractol->min.re -= delta.re * 0.05;
		fractol->max.re -= delta.re * 0.05;
	}
	else if (key == 0)
	{
		fractol->min.re += delta.re * 0.05;
		fractol->max.re += delta.re * 0.05;
	}
	else if (key == 1)
	{
		fractol->min.im += delta.im * 0.05;
		fractol->max.im += delta.im * 0.05;
	}
	else if (key == 13)
	{
		fractol->min.im -= delta.im * 0.05;
		fractol->max.im -= delta.im * 0.05;
	}
	choose_fractol(fractol);
}

void	put_pixel(t_fractol *fractol, int x, int y, t_color color)
{
	int i;

	i = (x * fractol->bits_per_pixel / 8) + (y * fractol->size_line);
	fractol->data_addr[i] = color.channel[3];
	fractol->data_addr[++i] = color.channel[2];
	fractol->data_addr[++i] = color.channel[1];
	fractol->data_addr[++i] = color.channel[0];
}

void	choose_fractol(t_fractol *fractol)
{
	if (fractol->num_f == 1)
		draw_mandelbrot(fractol);
	else if (fractol->num_f == 2)
		draw_julia(fractol);
	else if (fractol->num_f == 3)
		draw_celticmandelbrot(fractol);
	else if (fractol->num_f == 4)
		draw_burningship(fractol);
	else if (fractol->num_f == 5)
		draw_mandelbar(fractol);
	else if (fractol->num_f == 6)
		draw_celticmandelbar(fractol);
}
