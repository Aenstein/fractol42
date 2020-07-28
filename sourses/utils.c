/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 13:34:06 by aenstein          #+#    #+#             */
/*   Updated: 2020/07/28 18:06:53 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_color		get_color(int i, t_fractol *fractol)
{
	t_color		color;
	double		t;

	t = (double)i / fractol->iter;
	color.channel[0] = 0;
	color.channel[1] = (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[2] = (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[3] = (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

void		image_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fractol");
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->data_addr = mlx_get_data_addr(fractol->img,
		&(fractol->bits_per_pixel), &(fractol->size_line), &(fractol->endian));
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

double		changing(double start, double end, double change)
{
	return (start + ((end - start) * change));
}

void		zoom(int button, int x, int y, t_fractol *fractol)
{
	t_complex	mouse;
	double		zoom;
	double		change;

	mouse = init_complex((double)x / (WIDTH / (fractol->max.re -
		fractol->min.re)) + fractol->min.re, (double)y / (HEIGHT /
			(fractol->max.im - fractol->min.im)) * -1 + fractol->max.im);
	if (button == 4)
	{
		zoom = 0.8;
		fractol->iter -= 1;
	}
	else
	{
		zoom = 1.2;
		fractol->iter += 1;
	}
	change = 1.0 / zoom;
	fractol->min.re = changing(mouse.re, fractol->min.re, change);
	fractol->min.im = changing(mouse.im, fractol->min.im, change);
	fractol->max.re = changing(mouse.re, fractol->max.re, change);
	fractol->max.im = changing(mouse.im, fractol->max.im, change);
	choose_fractol(fractol);
}
