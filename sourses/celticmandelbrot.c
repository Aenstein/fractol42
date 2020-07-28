/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celticmandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenocka <lenocka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:38:44 by lenocka           #+#    #+#             */
/*   Updated: 2020/06/22 17:45:56 by lenocka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		celticmandelbrot(t_fractol *fractol)
{
	int			i;
	t_complex	z;

	i = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && i < fractol->iter)
	{
		z = init_complex(fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) +
		fractol->c.re, 2.0 * z.re * z.im + fractol->c.im);
		i++;
	}
	return (i);
}

void	draw_celticmandelbrot(t_fractol *fractol)
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
			i = celticmandelbrot(fractol);
			color = get_color(i, fractol);
			put_pixel(fractol, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}