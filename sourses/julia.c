/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenstein <aenstein@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 09:29:56 by aenstein          #+#    #+#             */
/*   Updated: 2020/07/26 15:22:32 by aenstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia_motion(int x, int y, t_fractol *fractol)
{
	if (x < 800 && y < 800 && x > 0 && y > 0)
	{
		fractol->k = init_complex(4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	}
}

int		julia(t_fractol *fractol)
{
	int			i;
	t_complex	z;

	i = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i < fractol->iter)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->k.re,
			2.0 * z.re * z.im + fractol->k.im);
		i++;
	}
	return (i);
}

void	draw_julia(t_fractol *fractol)
{
	int			x;
	int			y;
	int			i;
	t_color		color;

	fractol->factor = init_complex((fractol->max.re - fractol->min.re) /
		(WIDTH - 1), (fractol->max.im - fractol->min.im) / (HEIGHT - 1));
	y = 0;
	while (y < HEIGHT)
	{
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			i = julia(fractol);
			color = get_color(i, fractol);
			put_pixel(fractol, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}
